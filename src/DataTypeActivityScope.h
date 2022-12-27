/*
 * DataTypeActivityScope.h
 *
 *  Created on: Jun 4, 2022
 *      Author: mballance
 */

#pragma once
#include "zsp/arl/dm/IDataTypeActivityScope.h"
#include "DataTypeStruct.h"

namespace zsp {
namespace arl {
namespace dm {


class DataTypeActivityScope : public virtual IDataTypeActivityScope {
public:
	DataTypeActivityScope(const std::string &name);

	virtual ~DataTypeActivityScope();

	virtual const std::string &name() const override { return m_name; }

	virtual void addField(vsc::dm::ITypeField *f) override;

	virtual const std::vector<vsc::dm::ITypeFieldUP> &getFields() const override {
		return m_fields;
	}

	virtual vsc::dm::ITypeField *getField(int32_t idx) override {
		return m_fields.at(idx).get();
	}

	virtual void addConstraint(vsc::dm::ITypeConstraint *c) override;

	virtual const std::vector<vsc::dm::ITypeConstraintUP> &getConstraints() const override {
		return m_constraints;
	}

	virtual vsc::dm::IModelStructCreateHook *getCreateHook() const override {
		return m_create_hook.get();
	}

	virtual void setCreateHook(vsc::dm::IModelStructCreateHook *hook) override {
		m_create_hook = vsc::dm::IModelStructCreateHookUP(hook);
	}

	virtual const std::vector<ITypeFieldActivity *> &getActivities() const override {
		return m_activities;
	}

	virtual void addActivity(ITypeFieldActivity *a) override;

	virtual void addActivityField(ITypeFieldActivity *a) override;

	virtual vsc::dm::IModelField *mkRootField(
		vsc::dm::IModelBuildContext		*ctxt,
		const std::string			&name,
		bool						is_ref) override;

	virtual vsc::dm::IModelField *mkTypeField(
		vsc::dm::IModelBuildContext		*ctxt,
		vsc::dm::ITypeField				*type) override;

private:
	std::string									m_name;
	std::vector<vsc::dm::ITypeFieldUP>				m_fields;
	std::vector<vsc::dm::ITypeConstraintUP>			m_constraints;
	vsc::dm::IModelStructCreateHookUP				m_create_hook;

	std::vector<ITypeFieldActivity *>			m_activities;
	std::vector<ITypeFieldActivityUP>			m_activities_up;

};

}
}
}

