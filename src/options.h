/* -*- Mode: C; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
/*
 *    options.h
 *    This file is part of content-defined-cut (cdc) project.
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
 * @file options.h
 *
 *  This file contains all the definitions for the cut program.
 */
#ifndef _OPTIONS_H_
#define _OPTIONS_H_


/**
 * @struct options_t
 * @brief Selected options structure.
 *
 * Structure options_t gives a way to store program options passed from the
 * command line or read from a configuration file.
 */
typedef struct
{
    gboolean version;      /**< TRUE if we have to display program's version                   */
    gboolean adler_update; /**< TRUE to select the updating form of adler's librsync algorithm */
    gboolean adler;        /**< TRUE to select adler's librsync algorithm                      */
    GSList *file_list;     /**< list of files */
} options_t;


/**
 * This function parses command line options.
 * @param argc : number of arguments given on the command line.
 * @param argv : an array of strings that contains command line arguments.
 */
extern options_t *manage_command_line_options(int argc, char **argv);


/**
 * Frees the options structure if necessary
 * @param opt : the malloc'ed options_t structure
 */
extern void free_options_t(options_t *opt);


#endif /* _OPTIONS_H_ */
