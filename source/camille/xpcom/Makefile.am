# Stat is a portable C++ API to stat(2).
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

CLEANFILES = *.xpt
DISTCLEANFILES = *~

SUFFIXES = .idl .xpt

lib_LTLIBRARIES = libnsStat.la
libnsStat_la_SOURCES = nsStat.cpp nsStat.h nsIStat.h
libnsStat_la_LIBADD = ../src/Stat.lo
EXTRA_DIST = nsIStat.idl nsStat.js

BUILT_SOURCES = nsIStat.h

# In Automake 1.5 this becomes libnsStat_la_CXXFLAGS = ...
AM_CXXFLAGS = $(XPIDLCXXFLAGS)

%.h: %.idl
	@$(XPIDL) $(XPIDLFLAGS) -m header $?

%.xpt: %.idl
	@$(XPIDL) $(XPIDLFLAGS) -m typelib $?

# Use template in nsIStat.h to create nsStat.h and nsStat.cpp.
