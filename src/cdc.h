/* -*- Mode: C; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
/*
 *    cdc.h
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
 * @file cdc.h
 *
 *  This file contains all the definitions for the cut program.
 */
#ifndef _CDC_H_
#define _CDC_H_

/* Configuration from ./configure script */
#include "config.h"

#include <stdio.h>
#include <glib.h>
#include <gio/gio.h>
#include <glib-unix.h>
#include <glib/gi18n-lib.h>
#include <libcdpfgl.h>

#include "options.h"


/**
 * @def CDC_DATE
 * Defines cdc's creation date
 *
 * @def CDC_AUTHORS
 * Defines cdc's main authors
 *
 * @def CDC_LICENSE
 * Defines cdc's license (GPL v3 or later)
 *
 * @def CDC_VERSION
 * Defines cdc's version.
 *
 * @def PROGRAM_NAME
 * Defines the main program name for this part (cdc)
 */
#define CDC_AUTHORS ("Olivier DELHOMME <olivier.delhomme@free.fr>")
#define CDC_DATE _("09 10 2016")
#define CDC_LICENSE _("GPL v3 or later")
#define CDC_VERSION _("0.0.1")
#define PROGRAM_NAME ("cdc")



#endif /* #IFNDEF _CDC_H_ */
