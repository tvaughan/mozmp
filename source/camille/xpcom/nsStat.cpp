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

/* void setFile (in string file); */
NS_IMETHODIMP nsStat::SetFile(const char *file)
{
  s->setFile(file);
}

/* void getFile (out string file); */
NS_IMETHODIMP nsStat::GetFile(char **file)
{
  *file = s->getFile();
}

/* void mTime (inout string b, in unsigned long bsize); */
NS_IMETHODIMP nsStat::MTime(char **b, PRUint32 bsize)
{
  *b = s->mTime(*b, bsize);
}
