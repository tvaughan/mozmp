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

#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif /* HAVE_SYS_STAT_H */

#ifdef STDC_HEADERS
#include <stdlib.h>
#endif /* STDC_HEADERS */

#ifdef HAVE_STRING_H
#include <string.h>
#endif /* HAVE_STRING_H */

#include <stdio.h>

#include "Stat.h"

#if 0
#define DEBUG(x)	fprintf x
#else
#define DEBUG(x)
#endif /* 0 */

#define MAXBUFFERSIZE	256

Stat::Stat(void)
{
  mStat = (struct stat *) malloc(sizeof(struct stat));

  mStatCalled = 0;

  mFileStr = NULL;
  mTimeStr = (char *) malloc(MAXBUFFERSIZE);
}

Stat::~Stat(void)
{
  free(mStat);

  if (mFileStr)
    free(mFileStr);

  if (mTimeStr)
    free(mTimeStr);
}

void
Stat::setFile(const char *aFile)
{
  if (!aFile)
    return;

  mStatCalled = 0;

  if (mFileStr)
    free(mFileStr);
  mFileStr = strdup(aFile);

  DEBUG((stderr, "setFile \"%s\"\n", mFileStr));
}

char *
Stat::getFile(void)
{
  DEBUG((stderr, "getFile \"%s\"\n", mFileStr));

  return mFileStr;
}

void
Stat::callStat(void)
{
  if (mStatCalled)
    return;

  mStatCalled = 1;

  stat(mFileStr, (struct stat *) mStat);
}

char *
Stat::mTime(void)
{
  struct tm *tm;

  if (!mFileStr)
    return NULL;

  callStat();

  /*
   * TODO: localtime_r should be used.
   */
  tm = localtime(&((struct stat *) mStat)->st_mtime);
  strftime(mTimeStr, MAXBUFFERSIZE, "%a %b %d %T %Y", tm);

  DEBUG((stderr, "mTime \"%s\"\n", mTimeStr));

  return mTimeStr;
}
