/*
 FOGSim, simulator for interconnection networks.
 https://code.google.com/p/fogsim/
 Copyright (C) 2014 University of Cantabria

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef PBMSG_H
#define	PBMSG_H

#include "global.h"
#include <assert.h>
#include <iostream>

class creditFlit;

/* 
 * PiggyBacking Message: 
 * Message with info about global links state, 
 * to be sent between switches within the same group
 */
class pbFlit {
public:
	pbFlit(int srcOffset, bool ** globalLinkCongested, int arrivalCycle);
	pbFlit(const pbFlit& original);
	virtual ~pbFlit();
	int GetArrivalCycle() const;
	bool GetGlobalLinkInfo(int n, int channel) const;
	int GetSrcOffset() const;
	/* Priority comparison */
	bool operator <(const pbFlit& flit) const;
	long long GetId() const;
	int GetGeneratedCycle() const;

	static long long id;

private:
	/* Message source switch offset to index the global link array */
	int m_srcOffset;
	/*
	 * Pointer to an array with one bool per
	 * global link in the source switch
	 * (size = g_dH)
	 */
	bool **m_globalLinkInfo;
	int m_arrivalCycle;
	int m_generatedCycle;
	long long m_id;
};

#endif	/* PBMSG_H */

