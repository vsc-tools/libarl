/**
 * IDataTypeStruct.h
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
#include "vsc/dm/IDataTypeStruct.h"
#include "zsp/arl/dm/IDataTypeFunction.h"
#include "zsp/arl/dm/ITypeExecGroup.h"

namespace zsp {
namespace arl {
namespace dm {

class IDataTypeArlStruct;
using IDataTypeArlStructUP=std::unique_ptr<IDataTypeArlStruct>;
class IDataTypeArlStruct : public virtual vsc::dm::IDataTypeStruct {
public:

    virtual ~IDataTypeArlStruct() { }

    virtual const std::vector<ITypeExecUP> &getExecs(ExecKindT kind) const = 0;

    virtual void addExec(ITypeExec *exec) = 0;

    virtual void addFunction(IDataTypeFunction *f, bool owned=true) = 0;

    virtual const std::vector<IDataTypeFunctionUP> &getFunctions() = 0;

};

} /* namespace dm */
} /* namespace arl */
} /* namespace zsp */


