dnl Camille is a portable C++ API to stat(2).
dnl Copyright (C) 2000  Tom Vaughan
dnl
dnl This program is free software; you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License as published by
dnl the Free Software Foundation; either version 2 of the License, or
dnl (at your option) any later version.
dnl
dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl
dnl You should have received a copy of the GNU General Public License
dnl along with this program; if not, write to the Free Software
dnl Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

AC_DEFUN([AC_PROG_XPIDL],[
AC_PATH_PROG([XPIDL], [xpidl], [], [${PATH}:/usr/lib/mozilla-firefox])
test -z "${XPIDL}" && AC_MSG_ERROR(xpidl was not found on this system)
])

AC_DEFUN([AC_XPCOM],[
AC_PROG_XPIDL
XPCOMCFLAGS="`pkg-config --cflags firefox-xpcom`"
AC_SUBST(XPCOMCFLAGS)
XPCOMLDFLAGS="`pkg-config --libs firefox-xpcom`"
AC_SUBST(XPCOMLDFLAGS)
])
