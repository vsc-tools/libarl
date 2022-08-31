/*
 * IModelActivityParallel.h
 *
 *  Created on: Jun 5, 2022
 *      Author: mballance
 */

#pragma once
#include <vector>
#include "arl/IModelActivity.h"
#include "vsc/IModelField.h"

namespace arl {

class IModelActivityParallel;
using IModelActivityParallelUP=std::unique_ptr<IModelActivityParallel>;
class IModelActivityParallel : 
	public virtual IModelActivity, 
	public virtual vsc::IModelField {
public:

	virtual ~IModelActivityParallel() { }

	virtual const std::vector<IModelActivity *> &branches() const = 0;

	virtual void addBranch(IModelActivity *a) = 0;

	// TODO: Need an optional join-spec
	// Implicit (not supplied) == join_all


};

}

