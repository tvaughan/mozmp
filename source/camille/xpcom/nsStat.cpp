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

#include "nsIStat.h"
#include "nsStat.h"

NS_IMPL_ISUPPORTS1(nsStat, nsIStat)

nsStat::nsStat()
{
  NS_INIT_ISUPPORTS();

  s = new Stat();
}

nsStat::~nsStat()
{
  delete s;
}

/* attribute string file; */
NS_IMETHODIMP nsStat::GetFile(char * *aFile)
{
  *aFile = s->getFile();
  return NS_OK;
}
NS_IMETHODIMP nsStat::SetFile(const char * aFile)
{
  s->setFile(aFile);
  return NS_OK;
}

/* string mTime (); */
NS_IMETHODIMP nsStat::MTime(char **_retval)
{
  *_retval = s->mTime();
  return NS_OK;
}
