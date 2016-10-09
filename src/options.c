/* -*- Mode: C; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
/*
 *    options.c
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
 * @file src/options.c
 *
 *  This file contains all the functions to manage command line options.
 */

#include "cdc.h"

/**
 * This function parses command line options. It sets the options in this
 * order. It means that the value used for an option is the one set in the
 * lastest step.
 * 0) default values are set into the options_t * structure
 * 1) reads the default configuration file if any.
 * 2) reads the configuration file mentionned on the command line.
 * 3) sets the command line options (except for the list of directories,
 *    all other values are replaced by thoses in the command line)
 * @param argc : number of arguments given on the command line.
 * @param argv : an array of strings that contains command line arguments.
 * @returns options_t structure malloc'ed and filled upon choosen command
 *          line's option
 */
options_t *manage_command_line_options(int argc, char **argv)
{
    options_t *opt = NULL;    /** Structure to manage program's options            */
    gchar *summary = NULL;    /** Abstract for the program                         */
    gchar **dirname_array = NULL;  /** array of dirnames left on the command line             */

    gboolean version = FALSE;      /** True if -v was selected on the command line            */

    GOptionEntry entries[] =
    {
        { "version", 'v', 0, G_OPTION_ARG_NONE, &version, N_("Prints program version"), NULL },
        { G_OPTION_REMAINING, 0, 0, G_OPTION_ARG_FILENAME_ARRAY, &dirname_array, "", NULL},
        { NULL }
    };

    summary = g_strdup(_("This program should ease test of algorithms to content-define cut files"));
    parse_command_line(argc, argv, entries, summary);

    opt = (options_t *) g_malloc0(sizeof(options_t));

    opt->version = version; /* only TRUE if -v or --version was invoked */
    opt->file_list = NULL;
    opt->file_list = convert_gchar_array_to_GSList(dirname_array, opt->file_list);

    g_strfreev(dirname_array);

    return opt;
}


/**
 * Frees the options structure if necessary
 * @param opt : the malloc'ed options_t structure
 */
void free_options_t(options_t *opt)
{
    if (opt != NULL)
        {
            free_list(opt->file_list);
            g_free(opt);
        }
}
