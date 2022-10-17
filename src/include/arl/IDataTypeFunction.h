/**
 * IDataTypeFunction.h
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
#include <memory>
#include <string>
#include <vector>
#include "arl/IDataTypeFunctionParamDecl.h"
#include "arl/ITypeProcStmtScope.h"
#include "vsc/IAccept.h"
#include "vsc/IDataType.h"

namespace arl {

class IDataTypeFunction;
using IDataTypeFunctionUP=std::unique_ptr<IDataTypeFunction>;
class IDataTypeFunction : public vsc::IAccept {
public:

    virtual ~IDataTypeFunction() { }

    virtual const std::string &name() const = 0;

    virtual vsc::IDataType *getReturnType() const = 0;

    virtual const std::vector<IDataTypeFunctionParamDeclUP> &getParameters() const = 0;

    virtual void addParameter(IDataTypeFunctionParamDecl *p) = 0;

    virtual ITypeProcStmtScope *getBody() const = 0;

};

} /* namespace arl */


