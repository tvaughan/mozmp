/*
 * Camille is a portable C++ API to stat(2).
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

#ifdef HAVE_CONFIG_H
#include "configStat.h"
#endif /* HAVE_CONFIG_H */

#ifdef TIME_WITH_SYS_TIME
#include <sys/time.h>
#include <time.h>
#else
#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#else
#include <time.h>
#endif /* HAVE_SYS_TIME_H */
#endif /* TIME_WITH_SYS_TIME */

#ifdef TM_IN_SYS_TIME
#include <sys/time.h>
#endif /* TM_IN_SYS_TIME */

#ifdef HAVE_UNISTD_H
#include <sys/types.h>
#include <unistd.h>
#endif /* HAVE_UNISTD_H */

#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif /* HAVE_SYS_STAT_H */

#ifdef STDC_HEADERS
#include <stdlib.h>
#endif /* STDC_HEADERS */

#include <stdio.h>

#include "Stat.h"

#define BUFFERSIZE 256

#if 0
#define DEBUG(x)	fprintf x
#else
#define DEBUG(x)
#endif /* 0 */

Stat::Stat(void)
{
  mStat = (struct stat *) malloc(sizeof(struct stat));
  mFile = new char[BUFFERSIZE + 1];
  mBuffer = new char[BUFFERSIZE + 1];
  mStatCalled = 0;
}

Stat::~Stat(void)
{
  free(mStat);
  delete mFile;
  delete mBuffer;
}

void
Stat::setFile(const char *file)
{
  if (!file)
    return;

#ifdef HAVE_SNPRINTF
  snprintf(mFile, BUFFERSIZE, file);
#else
  sprintf(mFile, file);
#endif /* HAVE_SNPRINTF */

  DEBUG((stderr, "setFile \"%s\"\n", mFile));

  mStatCalled = 0;
}

char *
Stat::getFile(void)
{
  DEBUG((stderr, "getFile \"%s\"\n", mFile));

  return mFile;
}

void
Stat::callStat(void)
{
  if (!mStatCalled) {
    stat(mFile, (struct stat *) mStat);
    mStatCalled = 1;
  }
}

char *
Stat::mTime(void)
{
  struct tm *tm;

  callStat();

  /*
   * TODO: localtime_r should be used.
   */
  tm = localtime(&((struct stat *) mStat)->st_mtime);
  strftime(mBuffer, BUFFERSIZE, "%a %b %d %T %Y", tm);

  DEBUG((stderr, "mTime \"%s\"\n", mBuffer));

  return mBuffer;
}
