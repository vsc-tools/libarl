/*
 * DataTypeResource.cpp
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
#include "vsc/IVisitor.h"
#include "DataTypeResource.h"


namespace zsp {
namespace arl {
namespace dm {


DataTypeResource::DataTypeResource(
        IContext            *ctxt,
        const std::string   &name) : DataTypeFlowObj(ctxt, name, FlowObjKindE::Resource) {
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

    m_instance_id = ctxt->mkTypeFieldPhy(
        "instance_id",
        ui32_t,
        false,
        vsc::TypeFieldAttr::Rand,
        0);
    addField(m_instance_id);

    m_initial = ctxt->mkTypeFieldPhy(
        "initial",
        ui1_t,
        false,
        vsc::TypeFieldAttr::Rand,
        0);
    addField(m_initial);
}

DataTypeResource::~DataTypeResource() {

}

void DataTypeResource::accept(vsc::IVisitor *v) {
    if (dynamic_cast<IVisitor *>(v)) {
        dynamic_cast<IVisitor *>(v)->visitDataTypeResource(this);
    } else if (v->cascade()) {
        v->visitDataTypeStruct(this);
    }
}

}
}
}
