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

#ifndef __STAT_H__
#define __STAT_H__

#define CA_MAXBUFFERSIZE 256

class Stat
{
 private:
  void *mStat;
  char *mFile;
  char mTimeStr[CA_MAXBUFFERSIZE];
  bool mStatCalled;
  void callStat(void);

 public:
  Stat(void);
  virtual ~Stat(void);
  void setFile(const char *);
  char *getFile(void);
  char *mTime(void);
};

#endif /* __STAT_H__ */
