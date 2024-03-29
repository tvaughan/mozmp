/* -*- Mode: Java -*- */
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

function mozmpOpen()
{
    try {
	const FILEPICKER_CONTRACTID = '@mozilla.org/filepicker;1';
	const FILEPICKER_IID = Components.interfaces.nsIFilePicker;
	fp = Components.classes[FILEPICKER_CONTRACTID].createInstance(FILEPICKER_IID);
	fp.init(window, "Open File...", FILEPICKER_IID.modeOpen);
	fp.appendFilters(FILEPICKER_IID.filterAll);

	if (fp.show() == FILEPICKER_IID.returnOK) {
	    const STAT_CONTRACTID = '@mozilla.org/Camille;1';
	    const STAT_IID = Components.interfaces.nsIStat;
	    stat = Components.classes[STAT_CONTRACTID].createInstance(STAT_IID);
	    stat.file = fp.file.path;
	    s = stat.mTime();

	    d = document.getElementById('mozmp-display');
	    d.setAttribute("value", s);
	}
    }
    catch(e) {
	dump(e);
    }
}

function mozmpExit()
{
    close();
}

function mozmpAbout()
{
    alert('Hello World!');
}
