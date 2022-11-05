/*
 * DataTypeAction.cpp
 *
 *  Created on: Apr 16, 2022
 *      Author: mballance
 */

#include "DebugMacros.h"
#include "arl/IContext.h"
#include "vsc/IModelBuildContext.h"
#include "vsc/impl/TaskBuildModelFieldConstraints.h"
#include "DataTypeAction.h"
#include "ModelFieldAction.h"

namespace arl {

DataTypeAction::DataTypeAction(
		IContext			*ctxt,
		const std::string 	&name) : DataTypeStruct(name), m_component_t(0) {
    DEBUG_INIT("DataTypeAction");

	// Add the built-in 'comp' ref
	m_comp = ctxt->mkTypeFieldRef("comp", 0, vsc::TypeFieldAttr::NoAttr);
	addField(m_comp);
}

DataTypeAction::~DataTypeAction() {
	// TODO Auto-generated destructor stub
}

void DataTypeAction::setComponentType(IDataTypeComponent *t) {
	m_component_t = t;
    m_comp->setDataType(t);
}

void DataTypeAction::addActivity(ITypeFieldActivity *activity) {
	activity->setIndex(m_activities.size());
	m_activities.push_back(activity);
}

vsc::IModelField *DataTypeAction::mkRootField(
		vsc::IModelBuildContext		*ctxt,
		const std::string			&name,
		bool						is_ref) {
    DEBUG_ENTER("mkRootField %s", name.c_str());
	IContext *ctxt_a = dynamic_cast<IContext *>(ctxt->ctxt());
    IModelFieldAction *ret;

	ret = ctxt_a->mkModelFieldActionRoot(name, this);

    // Push the new field just for completeness
    ctxt->pushTopDownScope(ret);
    for (std::vector<vsc::ITypeFieldUP>::const_iterator 
        it=getFields().begin();
        it!=getFields().end(); it++) {
        vsc::IModelField *field = (*it)->mkModelField(ctxt);

        if (!field) {
            fprintf(stdout, "Error: Construction of field %s failed\n", (*it)->name().c_str());
        }
		ret->addField(field);
    }

	// Build out any activities
    if (activities().size() == 1) {
        ret->setActivity(dynamic_cast<IModelActivityScope *>(
            activities().at(0)->mkActivity(ctxt)));
    } else if (activities().size() > 1) {
        IModelActivityScope *schedule = ctxt_a->mkModelActivityScope(
            ModelActivityScopeT::Schedule);
    	// Build out any activities
    	for (std::vector<ITypeFieldActivity *>::const_iterator
    		it=activities().begin();
    		it!=activities().end(); it++) {
            IModelActivity *activity = (*it)->mkActivity(ctxt);
    		schedule->addActivity(activity);
    	}
        ret->setActivity(schedule);
    }

    // Finally, build out constraints on this field and sub-fields
    vsc::TaskBuildModelFieldConstraints<> constraint_builder(ctxt);
    constraint_builder.build(ret, this);

    if (getCreateHook()) {
        getCreateHook()->create(ret);
    }
    ctxt->popTopDownScope();

    DEBUG_LEAVE("mkRootField %s", name.c_str());
    return ret;	
}

vsc::IModelField *DataTypeAction::mkTypeField(
		vsc::IModelBuildContext		*ctxt,
		vsc::ITypeField				*type) {
    DEBUG_ENTER("mkTypeField %s", type->name().c_str());
	IContext *ctxt_a = dynamic_cast<IContext *>(ctxt->ctxt());

    IModelFieldAction *ret = ctxt_a->mkModelFieldActionType(type);


    // Push the new field just for completeness
    ctxt->pushTopDownScope(ret);
    for (std::vector<vsc::ITypeFieldUP>::const_iterator 
        it=getFields().begin();
        it!=getFields().end(); it++) {
        vsc::IModelField *field = (*it)->mkModelField(ctxt);
		ret->addField(field);
    }

    if (activities().size() == 1) {
        ret->setActivity(dynamic_cast<IModelActivityScope *>(
            activities().at(0)->mkActivity(ctxt)));

    } else if (activities().size() > 1) {
        IModelActivityScope *schedule = ctxt_a->mkModelActivityScope(
            ModelActivityScopeT::Schedule);
    	// Build out any activities
    	for (std::vector<ITypeFieldActivity *>::const_iterator
    		it=activities().begin();
    		it!=activities().end(); it++) {
            IModelActivity *activity = (*it)->mkActivity(ctxt);
    		schedule->addActivity(dynamic_cast<IModelActivityScope *>(activity));
    	}
    }

    // Finally, build out constraints on this field and sub-fields
    vsc::TaskBuildModelFieldConstraints<> constraint_builder(ctxt);
    constraint_builder.build(ret, this);

    if (getCreateHook()) {
        getCreateHook()->create(ret);
    }

    ctxt->popTopDownScope();

    DEBUG_LEAVE("mkTypeField %s", type->name().c_str());
    return ret;
}

void DataTypeAction::accept(vsc::IVisitor *v) {
	if (dynamic_cast<IVisitor *>(v)) {
		dynamic_cast<IVisitor *>(v)->visitDataTypeAction(this);
	} else if (v->cascade()) {
		v->visitDataTypeStruct(this);
	}
}

} /* namespace arl */
