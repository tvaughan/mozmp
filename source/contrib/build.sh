#! /bin/sh
# -*- Mode: Sh -*-

# The Mozilla Media Player is an audio and video player.
# Copyright (C) 2000  Tom Vaughan
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

PACKAGE=mozmp
PREFIX=/tmp/${PACKAGE}

# Let BSD users set "MAKE=gmake".
MAKE=${MAKE:=make}
if [ -z "`which ${MAKE}`" ]; then
    echo "${MAKE} not found on this system"
    exit 0
fi

MAKE=${MAKE} ./configure --disable-static --prefix=${PREFIX} || exit 0
${MAKE} -k install || exit 0

# TODO: Do this in camille/xpcom/Makefile.am.
${MAKE} -C camille/xpcom nsIStat.xpt || exit 0
cp -f camille/xpcom/*.xpt ${PREFIX}/lib

./create-xpi.sh
mv -f *.jar *.xpi ${PREFIX}
