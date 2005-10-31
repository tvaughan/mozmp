dnl The Mozilla Media Player is an audio and video player.
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

AC_DEFUN([AC_PROG_JAR],[
AC_CHECK_PROG(JAR, jar, jar)
test -z "${JAR}" && AC_MSG_ERROR(jar was not found on this system)
])

AC_DEFUN([AC_PROG_ZIP],[
AC_CHECK_PROG(ZIP, zip, zip)
test -z "${ZIP}" && AC_MSG_ERROR(zip was not found on this system)
])
