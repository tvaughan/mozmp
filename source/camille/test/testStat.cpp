/*
 * Stat is a portable C++ API to stat(2).
 * Copyright (C) 2000  Tom Vaughan
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <stdio.h>

#include "Stat.h"

#define BUFFERSIZE 256

int
main(int argc, char **argv)
{
  Stat *s;
  char *b;

  if (argc != 2) {
    fprintf(stderr, "Usage: testStat [filename]\n");
    exit(0);
  }

  s = new Stat();
  s->setFile((const char *) argv[1]);

  b = new char[BUFFERSIZE + 1];

  fprintf(stdout, "         File: %s\n", s->getFile());
  fprintf(stdout, "Last Modified: %s\n", s->mTime(b, BUFFERSIZE));

  delete s;

  delete b;

  exit(0);
}
