/**
 * IModelFieldExecutorGroup.h
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
#include <vector>
#include "vsc/dm/IDataTypeStruct.h"
#include "zsp/arl/dm/IModelFieldComponent.h"

namespace zsp {
namespace arl {
namespace dm {


class IModelFieldExecutor;

class IModelFieldExecutorGroup : public virtual IModelFieldComponent {
public:

    virtual ~IModelFieldExecutorGroup() { }

    virtual vsc::dm::IDataTypeStruct *getTraitType() const = 0;

    virtual const std::vector<IModelFieldExecutor *> getExecutors() const = 0;

    virtual void addExecutor(IModelFieldExecutor *executor) = 0;

};

}
}
}


