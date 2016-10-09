/* -*- Mode: C; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
/*
 *    cut.h
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
 *    along with "Sauvegarde".  If not, see <http://www.gnu.org/licenses/>
 */
/**
 * @file cut.h
 *
 *  This file contains all the definitions for the cut program.
 */
#ifndef _CUT_H_
#define _CUT_H_

/* Configuration from ./configure script */
#include "config.h"


#include <stdio.h>
#include <glib.h>
#include <gio/gio.h>
#include <glib-unix.h>

/**
 * @def CUT_DATE
 * Defines cut's creation date
 *
 * @def CUT_AUTHORS
 * Defines cut's main authors
 *
 * @def CUT_LICENSE
 * Defines cut's license (at least GPL v2)
 *
 * @def CUT_VERSION
 * Defines cut's version (which may be different of Sauvegarde's whole
 * project and programs that composes it).

 * @def PROGRAM_NAME
 * Defines the main program name for this part (cut)
 */
#define CUT_AUTHORS ("Olivier DELHOMME <olivier.delhomme@free.fr>")
#define CUT_DATE _("09 10 2016")
#define CUT_LICENSE _("GPL v3 or later")
#define CUT_VERSION _("0.0.1")
#define PROGRAM_NAME ("cut")



#endif /* #IFNDEF _CUT_H_ */
