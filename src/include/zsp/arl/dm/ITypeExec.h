/**
 * ITypeExec.h
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
#include "vsc/dm/IAccept.h"

namespace zsp {
namespace arl {
namespace dm {

enum class ExecKindT {
    Body,
    PreSolve,
    PostSolve,
};

class ITypeExec;
using ITypeExecUP=vsc::dm::UP<ITypeExec>;
class ITypeExec : public virtual vsc::dm::IAccept {
public:

    virtual ~ITypeExec() { }

    virtual ExecKindT getKind() const = 0;


};

} /* namespace dm */
} /* namespace arl */
} /* namespace zsp */


