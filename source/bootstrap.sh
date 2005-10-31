#!/bin/sh

libtoolize --copy --force --automake
aclocal
automake --add-missing --copy --force-missing --foreign
autoconf

(cd camille ; ./bootstrap.sh)
