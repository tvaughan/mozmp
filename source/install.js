/*
 * The Mozilla Media Player is an audio and video player.
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

mozmpName	= "Mozilla Media Player";
mozmpPackage	= "mozmp";
mozmpAuthor	= "Tom Vaughan";
mozmpVersion	= "0.0.2";

initInstall(mozmpName, mozmpAuthor + "/" + mozmpName, mozmpVersion);

var mozmpPackageFolder = getFolder("Chrome", mozmpPackage);
setPackageFolder(mozmpPackageFolder);

addDirectory(mozmpPackage);

registerChrome(CONTENT,	getFolder("Chrome", mozmpPackage + "/content"));
registerChrome(SKIN,	getFolder("Chrome", mozmpPackage + "/skin"));
registerChrome(LOCALE,	getFolder("Chrome", mozmpPackage + "/locale/en-US"));

performInstall();
