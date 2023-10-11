/*
 * IDataTypeAction.h
 *
 *  Created on: Apr 16, 2022
 *      Author: mballance
 */

#pragma once
#include "zsp/arl/dm/IAccept.h"
#include "zsp/arl/dm/ITypeExec.h"
#include "zsp/arl/dm/ITypeFieldActivity.h"
#include "zsp/arl/dm/IDataTypeArlStruct.h"
#include "vsc/dm/ITypeFieldRef.h"

namespace zsp {
namespace arl {
namespace dm {


class IDataTypeComponent;

class IDataTypeAction;
using IDataTypeActionUP=vsc::dm::UP<IDataTypeAction>;
class IDataTypeAction : public virtual arl::dm::IDataTypeArlStruct {
public:

	virtual IDataTypeComponent *getComponentType() = 0;

	virtual void setComponentType(IDataTypeComponent *) = 0;

	virtual vsc::dm::ITypeFieldRef *getCompField() const = 0;

	virtual const std::vector<ITypeFieldActivityUP> &activities() const = 0;

	virtual void addActivity(ITypeFieldActivity *activity) = 0;

    virtual int32_t getActivityOffset() const = 0;

};

}
}
}
