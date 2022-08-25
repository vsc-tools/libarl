/*
 * DataTypeStruct.h
 *
 *  Created on: Apr 16, 2022
 *      Author: mballance
 */

#pragma once
#include <string>
#include <vector>
#include "vsc/IContext.h"
#include "vsc/IDataTypeStruct.h"
#include "vsc/IModelBuildContext.h"
#include "vsc/IModelStructCreateHook.h"
#include "vsc/ITypeField.h"
#include "vsc/ITypeConstraint.h"

namespace arl {

class DataTypeStruct : public virtual vsc::IDataTypeStruct {
public:
	DataTypeStruct(const std::string &name);

	virtual ~DataTypeStruct();

	virtual const std::string &name() const {
		return m_name;
	}

	virtual void addField(vsc::ITypeField *f);

	virtual const std::vector<vsc::ITypeFieldUP> &getFields() const;

	virtual vsc::ITypeField *getField(int32_t idx);

	virtual void addConstraint(vsc::ITypeConstraint *c);

	virtual const std::vector<vsc::ITypeConstraintUP> &getConstraints() const;

	virtual vsc::IModelStructCreateHook *getCreateHook() const override;

	virtual void setCreateHook(vsc::IModelStructCreateHook *hook) override;

	virtual vsc::IModelField *mkRootField(
		vsc::IModelBuildContext		*ctxt,
		const std::string			&name,
		bool						is_ref) override;

	virtual vsc::IModelField *mkTypeField(
		vsc::IModelBuildContext		*ctxt,
		vsc::ITypeField				*type) override;

public:
	std::string								m_name;
	std::vector<vsc::ITypeFieldUP>		 	m_fields;
	std::vector<vsc::ITypeConstraintUP>		m_constraints;
	vsc::IModelStructCreateHookUP			m_create_hook;


};

} /* namespace arl */

