/*
 * TestBase.cpp
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
#include "TestBase.h"
#include "VscImpl.h"
#include "ArlImpl.h"


namespace zsp {
namespace arl {
namespace dm {


TestBase::TestBase() {

}

TestBase::~TestBase() {

}

void TestBase::SetUp() {
//    ArlImpl::inst()->init(vsc::VscImpl::inst()->getDebugMgr());
//    m_ctxt = IContextUP(
//        ArlImpl::inst()->mkContext(
//            vsc::VscImpl::inst()->mkContext()));
//    m_randstate = vsc::IRandStateUP(m_ctxt->mkRandState(""));
    enableDebug(false);
}

void TestBase::TearDown() {
    m_ctxt.reset();
}

void TestBase::enableDebug(bool en) {
//    vsc::VscImpl::inst()->getDebugMgr()->enable(en);
}

}
}
}
