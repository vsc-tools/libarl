/*
 * ModelActivitySchedule.cpp
 *
 *  Created on: Jun 6, 2022
 *      Author: mballance
 */

#include "zsp/arl/dm/IVisitor.h"
#include "ModelActivitySchedule.h"

namespace zsp {
namespace arl {
namespace dm {


ModelActivitySchedule::ModelActivitySchedule(
		const std::string		&name,
		IDataTypeActivity		*type) : 
		ModelActivityScope(ModelActivityScopeT::Schedule),
		m_name(name), m_type(type) {
	// TODO Auto-generated constructor stub

}

ModelActivitySchedule::~ModelActivitySchedule() {
	// TODO Auto-generated destructor stub
}

void ModelActivitySchedule::addActivity(IModelActivity *a, bool own) {
	m_activities.push_back(a);

	if (own) {
		m_activities_up.push_back(IModelActivityUP(a));
	}
}

void ModelActivitySchedule::accept(vsc::dm::IVisitor *v) {
	if (dynamic_cast<arl::dm::IVisitor *>(v)) {
		dynamic_cast<arl::dm::IVisitor *>(v)->visitModelActivitySchedule(this);
	}
}

}
}
}
