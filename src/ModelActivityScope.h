/**
 * ModelActivityScope.h
 *
 * Copyright 2022 Matthew Ballance and Contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may 
 * not use this file except in compliance with the License.  
 * You may obtain a copy of the License at:
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software 
 * distributed under the License is distributed on an "AS IS" BASIS, 
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  
 * See the License for the specific language governing permissions and 
 * limitations under the License.
 *
 * Created on:
 *     Author: 
 */
#pragma once
#include "arl/IModelActivityScope.h"
#include "ModelField.h"

namespace zsp {
namespace arl {
namespace dm {



class ModelActivityScope : public virtual IModelActivityScope, public ModelField {
public:
    ModelActivityScope(ModelActivityScopeT type);

    virtual ~ModelActivityScope();

	virtual ModelActivityScopeT getType() const override { return m_type; }

	virtual void setType(ModelActivityScopeT t) override {
        m_type = t;
    }

	virtual const std::string &name() const { return m_name; }

	virtual vsc::IDataType *getDataType() const { return 0; }

	virtual void setDataType(vsc::IDataType *t) override { }

	virtual const std::vector<IModelActivity *> &activities() const override {
		return m_activities;
	}

	virtual void addActivity(IModelActivity *a, bool own) override;

	virtual int32_t getNext() const override {
		return m_next;
	}

	virtual void setNext(int32_t n) override {
		m_next = n;
	}

	virtual IModelActivity *getActivity(int32_t i) { return m_activities.at(i); }

	virtual const std::vector<int32_t> &getRoots() const {
		return m_roots;
	}

	virtual void addRoot(int32_t r) {
		m_roots.push_back(r);
	}

	virtual void accept(vsc::IVisitor *v) override;


private:
ModelActivityScopeT                         m_type;
	std::string								m_name;
	std::vector<IModelActivity *>			m_activities;
	std::vector<IModelActivityUP>			m_activities_up;
	int32_t									m_next;
	std::vector<int32_t>					m_roots;

};

}
}
}


