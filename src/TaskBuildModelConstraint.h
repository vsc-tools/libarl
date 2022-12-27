/*
 * TaskBuildModelConstraint.h
 *
 *  Created on: Jun 17, 2022
 *      Author: mballance
 */

#pragma once
#include "arl/IModelBuildContext.h"
#include "vsc/impl/TaskBuildModelConstraint.h"

namespace zsp {
namespace arl {
namespace dm {


class TaskBuildModelConstraint : public vsc::TaskBuildModelConstraint<> {
public:
	TaskBuildModelConstraint(IModelBuildContext *ctxt);

	virtual ~TaskBuildModelConstraint();

};

}
}
}

