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

pkgName			= "mozmp";
pkgDisplayName		= "Mozilla Media Player";
pkgAuthor		= "mozmp.mozdev.org";
pkgVersion		= "0.0.2";

/* */

pkgRegistryKey	= pkgAuthor + "/" + pkgDisplayName;

initInstall(pkgDisplayName, pkgRegistryKey, pkgVersion);

var pkgNameFolder = getFolder("Chrome", pkgName);
setPackageFolder(pkgNameFolder);

addDirectory(pkgName);

pkgFolder = getFolder("Chrome", pkgName + "/content");
registerChrome(CONTENT | DELAYED_CHROME, pkgFolder);
pkgFolder = getFolder("Chrome", pkgName + "/skin/modern");
registerChrome(SKIN | DELAYED_CHROME, pkgFolder);
pkgFolder = getFolder("Chrome", pkgName + "/locale/en-US");
registerChrome(LOCALE | DELAYED_CHROME, pkgFolder);

performInstall();
