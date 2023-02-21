/*
 * IModelActivityScope.h
 *
 *  Created on: Jun 17, 2022
 *      Author: mballance
 */

#pragma once
#include <memory>
#include "vsc/dm/IModelField.h"
#include "zsp/arl/dm/IModelActivity.h"

namespace zsp {
namespace arl {
namespace dm {


enum class ModelActivityScopeT {
	Parallel,
	Replicate,
	Schedule,
	Sequence
};

class IModelActivityScope;
using IModelActivityScopeUP=vsc::dm::UP<IModelActivityScope>;
class IModelActivityScope : 
	public virtual vsc::dm::IModelField, 
	public virtual IModelActivity {
public:

	virtual ~IModelActivityScope() { }

	virtual ModelActivityScopeT getType() const = 0;

	virtual void setType(ModelActivityScopeT t) = 0;

	virtual const std::vector<IModelActivity *> &activities() const = 0;

	virtual void addActivity(IModelActivity *a, bool own=false)  = 0;

	virtual IModelActivity *getActivity(int32_t i) = 0;

	virtual const std::vector<int32_t> &getRoots() const = 0;

	virtual void addRoot(int32_t r) = 0;

};

}
}
}
