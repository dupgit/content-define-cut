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

    free_options_t(opt);
}
