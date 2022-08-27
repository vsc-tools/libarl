/*
 * ModelActivityTraverse.h
 *
 *  Created on: Jun 5, 2022
 *      Author: mballance
 */

#pragma once
#include "arl/IModelActivityTraverse.h"
#include "arl/IModelFieldAction.h"

namespace arl {

class ModelActivityTraverse : public IModelActivityTraverse {
public:
	ModelActivityTraverse(
			IModelFieldAction		*target,
			vsc::IModelConstraint	*with_c);

	virtual ~ModelActivityTraverse();

	virtual IModelFieldAction *getTarget() const {
		return m_target;
	}

	virtual vsc::IModelConstraint *getWithC() const {
		return m_with_c.get();
	}

	virtual void accept(vsc::IVisitor *v) override;

private:
	IModelFieldAction				*m_target;
	vsc::IModelConstraintUP			m_with_c;


};

} /* namespace arl */

