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

/*
 * Constants
 */
const STAT_CONTRACTID = '@mozilla.org/camille;1';
const STAT_CID = Components.ID('{6df20f63-68a0-4c51-a847-a3ba00b6e6b6}');
const STAT_IID = Components.interfaces.nsIStat;

/*
 * Classes
 */

/*
 * The nsStat class constructor.
 */
function nsStat() {
}

/*
 * The nsStat class.
 */
nsStat.prototype = {
    set file(f) {
	this.file = f;
    },

    get file() {
	return this.file;
    },

    mTime: function() {
	return this.MTime();
    },

    QueryInterface: function(iid) {
	if (!iid.equals(Components.interfaces.nsISupports) &&
	    !iid.equals(STAT_IID)) {
		throw Components.results.NS_ERROR_NO_INTERFACE;
	}
	return this;
    }
};

/*
 * Objects
 */

/*
 * The nsStat Module. For XPCOM registration.
 */
var nsStatModule = {
    registerSelf: function(compMgr, fileSpec, location, type) {
	compMgr.registerComponentWithType(STAT_CID, 
					  "nsStat component",
					  STAT_CONTRACTID,
					  fileSpec,
					  location,
					  true,
					  true,
					  type);
    },

    getClassObject: function(compMgr, cid, iid) {
	if (!cid.equals(STAT_CID)) {
	    throw Components.results.NS_ERROR_NO_INTERFACE;
	}

        if (!iid.equals(Components.interfaces.nsIFactory)) {
	    throw Components.results.NS_ERROR_NOT_IMPLEMENTED;
	}

	return nsStatFactory;
    },

    canUnload: function(compMgr) {
	return true;
    }
};

/*
 * The nsStat Class Factory.
 */
var nsStatFactory = {
    createInstance: function(outer, iid) {
	if (outer != null) {
	    throw Components.results.NS_ERROR_NO_AGGREGATION;
	}
    
	if (!iid.equals(STAT_IID) &&
	    !iid.equals(Components.interfaces.nsISupports)) {
		throw Components.results.NS_ERROR_INVALID_ARG;
	}

	return new nsStat();
    }
}

/*
 * Functions.
 */

/*
 * Module Initialization.
 */
function NSGetModule(comMgr, fileSpec) {
    return nsStatModule;
}
