/*
 * DataTypeFlowObj.cpp
 *
 *  Created on: Apr 16, 2022
 *      Author: mballance
 */
#include "arl/IVisitor.h"
#include "DataTypeFlowObj.h"

namespace arl {

DataTypeFlowObj::DataTypeFlowObj(
		IContext			*ctxt,
		const std::string	&name,
		FlowObjKindE 		kind) : DataTypeStruct(name), m_kind(kind) {
    vsc::IDataTypeInt *ui32_t = ctxt->findDataTypeInt(false, 32);

    if (!ui32_t) {
        ui32_t = ctxt->mkDataTypeInt(false, 32);
        ctxt->addDataTypeInt(ui32_t);
    }

    vsc::IDataTypeInt *ui1_t = ctxt->findDataTypeInt(false, 1);

    if (!ui1_t) {
        ui1_t = ctxt->mkDataTypeInt(false, 1);
        ctxt->addDataTypeInt(ui1_t);
    }

    m_poolid = ctxt->mkTypeFieldPhy(
        "pool_id",
        ui32_t,
        false,
        vsc::TypeFieldAttr::Rand,
        0);

}

DataTypeFlowObj::~DataTypeFlowObj() {
	// TODO Auto-generated destructor stub
}

void DataTypeFlowObj::accept(vsc::IVisitor *v) {
	if (dynamic_cast<IVisitor *>(v)) {
		dynamic_cast<IVisitor *>(v)->visitDataTypeFlowObj(this);
	} else if (v->cascade()) {
		v->visitDataTypeStruct(this);
	}
}

} /* namespace arl */
