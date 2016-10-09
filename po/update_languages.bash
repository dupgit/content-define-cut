#!/bin/bash
#    update_languages.bash
#    Updates all files for the translation system.
#
#    This file is part of content-define cut (cdc) project.
#
#    (C) Copyright 2016 Olivier Delhomme
#     e-mail : olivier.delhomme@free.fr
#
#    "Sauvegarde" is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    "Sauvegarde" is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with cdc project.  If not, see <http://www.gnu.org/licenses/>
#

rm cdc.po.old
mv cdc.po cdc.po.old

# Updating file list
./find_files.sh >./POTFILES.in

# Updating sauvegarde.po
xgettext --language=C --default-domain=cdc --add-comments --from-code=UTF-8 --keyword=N_:1 --keyword=_:1 -F --files-from=./POTFILES.in

sed -i -e "s/CHARSET/us-ascii/" cdc.po

LANGUAGES=

# updating translations
for l in ${LANGUAGES}; do
    msgmerge -U $l.po cdc.po;
done;

sed -i s,\.\.\/,, ./POTFILES.in
