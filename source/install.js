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

const name	= "Mozilla Media Player";
const package	= "mozmp";
const author	= "Tom Vaughan";
const version	= "0.0.1";

initInstall(name, author + "/" + name, version);

var packageFolder = getFolder("Chrome", package);
setPackageFolder(packageFolder);

addDirectory(package);

registerChrome(CONTENT,	getFolder("Chrome", package + "/content"));
registerChrome(SKIN,	getFolder("Chrome", package + "/skin"));
registerChrome(LOCALE,	getFolder("Chrome", package + "/locale/en-US"));

performInstall();
