/*
 * ModelActivityScope.cpp
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
#include "ModelActivityScope.h"


namespace arl {


ModelActivityScope::ModelActivityScope(ModelActivityScopeT type) : m_type(type) {

}

ModelActivityScope::~ModelActivityScope() {

}

void ModelActivityScope::addActivity(IModelActivity *a, bool own) {
    m_activities.push_back(a);
    if (own) {
        m_activities_up.push_back(IModelActivityUP(a));
    }
}

void ModelActivityScope::accept(vsc::IVisitor *v) {
    if (dynamic_cast<IVisitor *>(v)) {
        dynamic_cast<IVisitor *>(v)->visitModelActivityScope(this);
    }
}

}
