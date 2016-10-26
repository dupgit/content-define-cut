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
            fprintf(stdout, "%08jx\n", res);
            pos = pos + 1;
        }
}


/**
 * Calculates hash by updating it with RollsumRotate at each byte
 * @param sum is the structure to update to calculate hashs
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
            fprintf(stdout, "%08jx\n", res);
            pos = pos + 1;
        }
}


/**
 * Calculate a modified adler hash on one file
 * @param is the filename of the file to be processed
 * @param adler_update selects the updating version of librsync
 *        adler's algorithm when TRUE and the static version (that
 *        is expected to be much slower) if FALSE.
 */
static void operate_adler_on_one_file(gchar *filename, gboolean adler_update)
{
    GFileInputStream *stream = NULL;
    GError *error = NULL;
    guint read = 0;
    guint first_read = 0;
    gchar *buffer = NULL;
    gchar *buffer2 = NULL;
    gchar *buffer3 = NULL;
    gchar *buffer4 = NULL;
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
    buffer3 = (guchar *) g_malloc(2*len);

    first_read = g_input_stream_read((GInputStream *) stream, buffer, blocksize, NULL, &error);

    if (first_read > len)
        {
            if (adler_update == TRUE)
                {
                    RollsumInit(&sum);
                    RollsumUpdate(&sum, buffer, len);
                    calculate_hashs_for_buffer(&sum, buffer, first_read, len);
                }
            else
                {
                    calculate_hashs_for_buffer_no_update(buffer, first_read, len);
                }

            while (first_read != 0 && error == NULL)
                {
                    read = g_input_stream_read((GInputStream *) stream, buffer2, blocksize, NULL, &error);

                    if (read > 0)
                        {
                            /* We need to manage between buffers with the update operation */
                            memcpy(buffer3, buffer + first_read - len + 1, len - 1);
                            memcpy(buffer3 + len - 1, buffer2, len - 1);

                            if (adler_update == TRUE)
                                {
                                    calculate_hashs_for_buffer(&sum, buffer3, 2 * len - 2, len);
                                    calculate_hashs_for_buffer(&sum, buffer2, read, len);
                                }
                            else
                                {
                                    calculate_hashs_for_buffer_no_update(buffer3, 2 * len - 2, len);
                                    calculate_hashs_for_buffer_no_update(buffer2, read, len);
                                }

                            buffer4 = buffer2;
                            buffer2 = buffer;
                            buffer = buffer4;
                        }
                    first_read = read;
                }

        }

    g_free(buffer);
    g_free(buffer2);
    g_free(buffer3);
    g_input_stream_close((GInputStream *) stream, NULL, NULL);
    g_object_unref(stream);
    g_object_unref(a_file);
}


/**
 * Calculate hashs on each file of the list
 * @param opt is the options as selected on the command line.
 */
static void do_calculations_file_list(options_t *opt)
{
    GSList *file_list = NULL;
    gboolean adler_update = FALSE;

    if (opt != NULL)
        {
            file_list = opt->file_list;
            adler_update = opt->adler_update;


            while (file_list != NULL)
                {
                    if (opt->adler == TRUE)
                        {
                            operate_adler_on_one_file(file_list->data, adler_update);
                        }
                    file_list = g_slist_next(file_list);
                }
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
            do_calculations_file_list(opt);
        }

    free_options_t(opt);
}
