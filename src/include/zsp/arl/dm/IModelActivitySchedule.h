/*
 * IModelActivitySchedule.h
 *
 *  Created on: Jun 5, 2022
 *      Author: mballance
 */

#pragma once
#include <vector>
#include "arl/IModelActivityScope.h"

namespace arl {

class IModelActivitySchedule : public virtual IModelActivityScope {
public:

	virtual ~IModelActivitySchedule() { }

	// TODO: Need an optional join-spec
	// Implicit (not supplied) == join_all

};

}

