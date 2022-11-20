/*
 * DataTypeActivityBind.cpp
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
#include "arl/IVisitor.h"
#include "DataTypeActivityBind.h"


namespace arl {


DataTypeActivityBind::DataTypeActivityBind(
    const std::vector<vsc::ITypeExprFieldRef *> &targets) {
    for (std::vector<vsc::ITypeExprFieldRef *>::const_iterator
        it=targets.begin();
        it!=targets.end(); it++) {
        m_targets.push_back(vsc::ITypeExprFieldRefUP(*it));
    }
}

DataTypeActivityBind::~DataTypeActivityBind() {

}

void DataTypeActivityBind::accept(vsc::IVisitor *v) {
    if (dynamic_cast<IVisitor *>(v)) {
        dynamic_cast<IVisitor *>(v)->visitDataTypeActivityBind(this);
    }
}

}
