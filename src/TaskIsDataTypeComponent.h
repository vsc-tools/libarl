/*
 * TaskIsDataTypeComponent.h
 *
 *  Created on: May 18, 2022
 *      Author: mballance
 */

#pragma once
#include "arl/impl/VisitorBase.h"

namespace zsp {
namespace arl {
namespace dm {


class TaskIsDataTypeComponent : VisitorBase {
public:
	TaskIsDataTypeComponent();

	virtual ~TaskIsDataTypeComponent();

	IDataTypeComponent *check(vsc::IDataType *t);

	virtual void visitDataTypeComponent(IDataTypeComponent *t) override;

private:
	IDataTypeComponent				*m_comp;

};

}
}
}

