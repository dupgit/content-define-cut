/* -*- Mode: C; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
/*
 *    cdc.c
 *    This file is part of content-define-cut (cdc) project.
 *
 *    (C) Copyright 2016 Olivier Delhomme
 *     e-mail : olivier.delhomme@free.fr
 *
 *    "Sauvegarde" is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    "Sauvegarde" is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with cdc project.  If not, see <http://www.gnu.org/licenses/>
 */

/**
 * @file cdc.c
 */

#include "cdc.h"

/**
 * Calculates hash by recalculating it at each byte
 * @param buffer is a gchar * string containing a portion of the file
 * @param read is the number of bytes read that are in buffer
 * @param len is the window size len on which the hash is calculated
 */
void calculate_hashs_for_buffer_no_update(gchar *buffer, guint read, size_t len)
{
    size_t pos = 0;
    uint32_t res = 0;
    Rollsum sum;


    while (pos <= (read - len))
        {
            RollsumInit(&sum);
            RollsumUpdate(&sum, buffer + pos, len);
            res = RollsumDigest(&sum);
            fprintf(stdout, "%jx\n", res);
            pos = pos + 1;
        }
}


/**
 * Calculates hash by updating it with RollsumRotate at each byte
 * @param buffer is a gchar * string containing a portion of the file
 * @param read is the number of bytes read that are in buffer
 * @param len is the window size len on which the hash is calculated
 */
void calculate_hashs_for_buffer(Rollsum *sum, gchar *buffer, guint read, size_t len)
{
    size_t pos = 0;
    uint32_t res = 0;


    while (pos <= (read - len))
        {
            RollsumRotate(sum, buffer[pos], buffer[pos+len+1]);
            res = RollsumDigest(sum);
            fprintf(stdout, "%jx\n", res);
            pos = pos + 1;
        }
}


/**
 * Calculate a modified adler hash on one file
 * @param is the filename of the file to be processed
 */
static void operate_adler_on_one_file(gchar *filename)
{
    GFileInputStream *stream = NULL;
    GError *error = NULL;
    guint read = 0;
    gchar *buffer = NULL;
    gchar *buffer2 = NULL;
    guint blocksize = 16384;
    GFile *a_file = NULL;
    size_t len = 16;
    uint32_t res = 0;
    Rollsum sum;


    fprintf(stderr, _("File : %s\n"), filename);
    a_file = g_file_new_for_path(filename);
    stream = g_file_read(a_file, NULL, &error);

    buffer = (guchar *) g_malloc(blocksize);
    buffer2 = (guchar *) g_malloc(blocksize);
    read = g_input_stream_read((GInputStream *) stream, buffer, blocksize, NULL, &error);

    if (read > len)
        {
            RollsumInit(&sum);
            RollsumUpdate(&sum, buffer, len);

            calculate_hashs_for_buffer(&sum, buffer, read, len);

            while (read != 0 && error == NULL)
                {
                    read = g_input_stream_read((GInputStream *) stream, buffer2, blocksize, NULL, &error);
                    if (read > 0)
                        {
                            /* We need to manage between buffers with the update operation */
                            calculate_hashs_for_buffer(&sum, buffer, read, len);
                        }
                }

        }

    g_input_stream_close((GInputStream *) stream, NULL, NULL);
    g_object_unref(stream);
    g_object_unref(a_file);
}


/**
 * Calculate hashs on each file of the list
 * @param file_list is a list of gchar * representing filenames.
 */
static void do_calculations_file_list(GSList *file_list)
{

    while (file_list != NULL)
        {
            operate_adler_on_one_file(file_list->data);
            file_list = g_slist_next(file_list);
        }
}


/**
 * Main function
 * @param argc : number of arguments given on the command line.
 * @param argv : an array of strings that contains command line arguments.
 * @returns always 0
 */
int main(int argc, char **argv)
{
    options_t *opt = NULL;    /** Structure to manage program's options */


    opt = manage_command_line_options(argc, argv);

    if (opt->version == TRUE)
        {
            print_program_version(PROGRAM_NAME, CDC_DATE, CDC_VERSION, CDC_AUTHORS, CDC_LICENSE);
        }
    else
        {
            do_calculations_file_list(opt->file_list);
        }

    free_options_t(opt);
}
