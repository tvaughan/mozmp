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

mozmpName		= "mozmp";
mozmpDisplayName	= "Mozilla Media Player";
mozmpAuthor		= "Tom Vaughan";
mozmpVersion		= "0.0.2";
mozmpRegistryKey	= mozmpAuthor + "/" + mozmpDisplayName;

initInstall(mozmpDisplayName, mozmpRegistryKey, mozmpVersion);

var mozmpNameFolder = getFolder("Chrome", mozmpName);
setPackageFolder(mozmpNameFolder);

addDirectory(mozmpName);

registerChrome(CONTENT,	getFolder("Chrome", mozmpName + "/content"));
registerChrome(SKIN,	getFolder("Chrome", mozmpName + "/skin"));
registerChrome(LOCALE,	getFolder("Chrome", mozmpName + "/locale/en-US"));

performInstall();
