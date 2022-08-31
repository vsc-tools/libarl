/*
 * ModelActivityParallel.h
 *
 *  Created on: Jun 6, 2022
 *      Author: mballance
 */

#pragma once
#include "arl/IModelActivityParallel.h"
#include "ModelField.h"

namespace arl {

class ModelActivityParallel : 
	public virtual IModelActivityParallel,
	public virtual ModelField {
public:
	ModelActivityParallel();

	virtual ~ModelActivityParallel();

	virtual const std::vector<IModelActivity *> &branches() const override {
		return m_branches;
	}

	virtual void addBranch(IModelActivity *a) override {
		m_branches.push_back(a);
	}

	virtual void accept(vsc::IVisitor *v) override;

private:
	std::vector<IModelActivity *>				m_branches;

};

} /* namespace arl */

