/*
 * DataTypeActivityScope.cpp
 *
 *  Created on: Jun 4, 2022
 *      Author: mballance
 */

#include "DataTypeActivityScope.h"

namespace arl {

DataTypeActivityScope::DataTypeActivityScope(const std::string &name) :
		m_name(name) {
	// TODO Auto-generated constructor stub

}

DataTypeActivityScope::~DataTypeActivityScope() {
	// TODO Auto-generated destructor stub
}

void DataTypeActivityScope::addField(vsc::ITypeField *f) {
	f->setIndex(m_fields.size());
	f->setParent(this);
	m_fields.push_back(vsc::ITypeFieldUP(f));
}

void DataTypeActivityScope::addConstraint(vsc::ITypeConstraint *c) {
	m_constraints.push_back(vsc::ITypeConstraintUP(c));
}

void DataTypeActivityScope::addActivity(ITypeFieldActivity *a) {
	// A non-data-field activity. Owned by the activities collection
	a->setParent(this);
	m_activities.push_back(a);
	m_activities_up.push_back(ITypeFieldActivityUP(a));
}

void DataTypeActivityScope::addActivityField(ITypeFieldActivity *a) {
	a->setIndex(m_fields.size());
	a->setParent(this);
	m_activities.push_back(a);
	m_fields.push_back(vsc::ITypeFieldUP(a));
}

} /* namespace arl */
