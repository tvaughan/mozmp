#!/bin/sh

libtoolize --copy --force --automake
aclocal
autoheader
automake --add-missing --copy --force-missing --foreign
autoconf
