/**
 * RewriteVisitorBase.h
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
#include "vsc/dm/impl/RewriteVisitorBase.h"
#include "zsp/arl/dm/IVisitor.h"
#include "zsp/arl/dm/IDataTypeAction.h"
#include "zsp/arl/dm/IDataTypeActivityBind.h"
#include "zsp/arl/dm/IDataTypeActivityParallel.h"
#include "zsp/arl/dm/IDataTypeActivityReplicate.h"
#include "zsp/arl/dm/IDataTypeActivitySchedule.h"
#include "zsp/arl/dm/IDataTypeActivitySequence.h"
#include "zsp/arl/dm/IDataTypeActivityTraverse.h"
#include "zsp/arl/dm/IDataTypeComponent.h"
#include "zsp/arl/dm/IDataTypeFlowObj.h"
#include "zsp/arl/dm/IDataTypeFunction.h"
#include "zsp/arl/dm/IDataTypeFunctionParamDecl.h"
#include "zsp/arl/dm/IDataTypeResource.h"
#include "zsp/arl/dm/IModelActivityBind.h"
#include "zsp/arl/dm/IModelActivityParallel.h"
#include "zsp/arl/dm/IModelActivityReplicate.h"
#include "zsp/arl/dm/IModelActivitySchedule.h"
#include "zsp/arl/dm/IModelActivityScope.h"
#include "zsp/arl/dm/IModelActivitySequence.h"
#include "zsp/arl/dm/IModelActivityTraverse.h"
#include "zsp/arl/dm/IModelFieldAction.h"
#include "zsp/arl/dm/IModelFieldClaim.h"
#include "zsp/arl/dm/IModelFieldComponent.h"
#include "zsp/arl/dm/IModelFieldComponentRoot.h"
#include "zsp/arl/dm/IModelFieldExecutor.h"
#include "zsp/arl/dm/IModelFieldExecutorClaim.h"
#include "zsp/arl/dm/IModelFieldInOut.h"
#include "zsp/arl/dm/IModelFieldPool.h"
#include "zsp/arl/dm/IVisitor.h"
#include "zsp/arl/dm/ITypeExprMethodCallContext.h"
#include "zsp/arl/dm/ITypeExprMethodCallStatic.h"
#include "zsp/arl/dm/ITypeExecProc.h"
#include "zsp/arl/dm/ITypeFieldActivity.h"
#include "zsp/arl/dm/ITypeFieldClaim.h"
#include "zsp/arl/dm/ITypeFieldExecutor.h"
#include "zsp/arl/dm/ITypeFieldExecutorClaim.h"
#include "zsp/arl/dm/ITypeFieldInOut.h"
#include "zsp/arl/dm/ITypeFieldPool.h"
#include "zsp/arl/dm/ITypeProcStmtAssign.h"
#include "zsp/arl/dm/ITypeProcStmtBreak.h"
#include "zsp/arl/dm/ITypeProcStmtContinue.h"
#include "zsp/arl/dm/ITypeProcStmtExpr.h"
#include "zsp/arl/dm/ITypeProcStmtForeach.h"
#include "zsp/arl/dm/ITypeProcStmtIfElse.h"
#include "zsp/arl/dm/ITypeProcStmtMatch.h"
#include "zsp/arl/dm/ITypeProcStmtRepeat.h"
#include "zsp/arl/dm/ITypeProcStmtRepeatWhile.h"
#include "zsp/arl/dm/ITypeProcStmtReturn.h"
#include "zsp/arl/dm/ITypeProcStmtScope.h"
#include "zsp/arl/dm/ITypeProcStmtVarDecl.h"
#include "zsp/arl/dm/ITypeProcStmtWhile.h"


namespace zsp {
namespace arl {
namespace dm {


class RewriteVisitorBase :
    public virtual IVisitor,
    public virtual vsc::dm::RewriteVisitorBase {
public:
    RewriteVisitorBase() { }

    virtual ~RewriteVisitorBase() { }

	virtual void visitDataTypeAction(IDataTypeAction *i) override {
		m_this->visitDataTypeStruct(i);
		for (std::vector<ITypeFieldActivity *>::const_iterator
				it=i->activities().begin();
				it!=i->activities().end(); it++) {
			(*it)->accept(m_this);
		}
	}

	virtual void visitDataTypeActivityBind(IDataTypeActivityBind *t) override {
		for (std::vector<vsc::dm::ITypeExprFieldRefUP>::const_iterator
			it=t->getTargets().begin();
			it!=t->getTargets().end(); it++) {
			(*it)->accept(m_this);
		}
	}

	virtual void visitDataTypeActivityParallel(IDataTypeActivityParallel *t) override {
		m_this->visitDataTypeStruct(t);
	}

	virtual void visitDataTypeActivityReplicate(IDataTypeActivityReplicate *t) override {
		t->getCount()->accept(m_this);
		m_this->visitDataTypeStruct(t);
	}

	virtual void visitDataTypeActivitySchedule(IDataTypeActivitySchedule *t) override {
		m_this->visitDataTypeStruct(t);
	}

	virtual void visitDataTypeActivitySequence(IDataTypeActivitySequence *t) override {
		m_this->visitDataTypeStruct(t);
	}

	virtual void visitDataTypeActivityTraverse(IDataTypeActivityTraverse *t) override { }

	virtual void visitDataTypeComponent(IDataTypeComponent *t) override {
		m_this->visitDataTypeStruct(t);
	}

	virtual void visitDataTypeFlowObj(IDataTypeFlowObj *t) override {
		m_this->visitDataTypeStruct(t);
	}

	virtual void visitDataTypeFunction(IDataTypeFunction *t) override {

	}
    
	virtual void visitDataTypeFunctionParamDecl(IDataTypeFunctionParamDecl *t) override {
        t->getDataType()->accept(m_this);
        if (t->getInit()) {
            t->getInit()->accept(m_this);
        }
    }

	virtual void visitDataTypeResource(IDataTypeResource *t) override {
		visitDataTypeFlowObj(t);
	}

	virtual void visitModelActivityBind(IModelActivityBind *a) override {
		for (std::vector<vsc::dm::IModelExprUP>::const_iterator
			it=a->getTargets().begin();
			it!=a->getTargets().end(); it++) {
			(*it)->accept(m_this);
		}
	}

	virtual void visitModelActivityParallel(IModelActivityParallel *a) override {
		for (std::vector<IModelActivity *>::const_iterator
				it=a->branches().begin();
				it!=a->branches().end(); it++) {
			(*it)->accept(m_this);
		}
	}

	virtual void visitModelActivityReplicate(IModelActivityReplicate *a) override {
		a->getCountExpr()->accept(m_this);
		visitModelActivityScope(a);
	}

	virtual void visitModelActivitySchedule(IModelActivitySchedule *a) override {
		for (std::vector<IModelActivity *>::const_iterator
				it=a->activities().begin();
				it!=a->activities().end(); it++) {
			(*it)->accept(m_this);
		}
	}
	
	virtual void visitModelActivityScope(IModelActivityScope *a) override {
		for (std::vector<IModelActivity *>::const_iterator
				it=a->activities().begin();
				it!=a->activities().end(); it++) {
			(*it)->accept(m_this);
		}
	}

	virtual void visitModelActivitySequence(IModelActivitySequence *a) override {
		for (std::vector<IModelActivity *>::const_iterator
				it=a->activities().begin();
				it!=a->activities().end(); it++) {
			(*it)->accept(m_this);
		}
	}

	virtual void visitModelActivityTraverse(IModelActivityTraverse *a) override {
		a->getTarget()->accept(m_this);
		if (a->getWithC()) {
			a->getWithC()->accept(m_this);
		}
	}

	virtual void visitModelFieldAction(IModelFieldAction *f) override {
		m_this->visitModelField(f);
		if (f->getActivity()) {
			f->getActivity()->accept(m_this);
		}
	}

	virtual void visitModelFieldClaim(IModelFieldClaim *f) override { }

	virtual void visitModelFieldComponent(IModelFieldComponent *f) override {
		m_this->visitModelField(f);
	}

	virtual void visitModelFieldComponentRoot(IModelFieldComponentRoot *f) override {
		visitModelFieldComponent(f);
	}

	virtual void visitModelFieldExecutor(IModelFieldExecutor *f) override {
		m_this->visitModelField(f);
	}

	virtual void visitModelFieldExecutorClaim(IModelFieldExecutorClaim *f) override {
		m_this->visitModelFieldRef(f);
	}

	virtual void visitModelFieldInOut(IModelFieldInOut *f) override { }

	virtual void visitModelFieldPool(IModelFieldPool *f) override {
		m_this->visitModelField(f);
	}

    virtual void visitTypeExprMethodCallContext(ITypeExprMethodCallContext *e) override {
        visitTypeExprMethodCallStatic(e);
        e->getContext()->accept(m_this);
    }

    virtual void visitTypeExprMethodCallStatic(ITypeExprMethodCallStatic *e) override {
        e->getTarget()->accept(m_this);
    }

	virtual void visitTypeExec(ITypeExec *e) override { }

	virtual void visitTypeExecProc(ITypeExecProc *e) override {
        dynamic_cast<IVisitor *>(m_this)->visitTypeExec(e);
        e->getBody()->accept(m_this);
    }

	virtual void visitTypeFieldActivity(ITypeFieldActivity *f) override {
		m_this->visitTypeField(f);
	}

	virtual void visitTypeFieldClaim(ITypeFieldClaim *f) override {
		m_this->visitTypeFieldRef(f);
	}

	virtual void visitTypeFieldExecutor(ITypeFieldExecutor *f) override {
		m_this->visitTypeField(f);
	}

	virtual void visitTypeFieldExecutorClaim(ITypeFieldExecutorClaim *f) override {
		m_this->visitTypeFieldRef(f);
	}

	virtual void visitTypeFieldInOut(ITypeFieldInOut *f) override {
		m_this->visitTypeFieldRef(f);
	}

	virtual void visitTypeFieldPool(ITypeFieldPool *f) override {
		m_this->visitTypeField(f);
	}

	virtual void visitTypeProcStmtAssign(ITypeProcStmtAssign *s) override {
		s->getLhs()->accept(m_this);
		s->getRhs()->accept(m_this);
	}

	virtual void visitTypeProcStmtBreak(ITypeProcStmtBreak *s) override {

	}

	virtual void visitTypeProcStmtContinue(ITypeProcStmtContinue *s) override {

	}

	virtual void visitTypeProcStmtExpr(ITypeProcStmtExpr *s) override {
        s->getExpr()->accept(m_this);
	}

	virtual void visitTypeProcStmtForeach(ITypeProcStmtForeach *s) override {

	}

	virtual void visitTypeProcStmtIfElse(ITypeProcStmtIfElse *s) override {
		s->getCond()->accept(m_this);
		s->getTrue()->accept(m_this);
		if (s->getFalse()) {
			s->getFalse()->accept(m_this);
		}
	}

	virtual void visitTypeProcStmtMatch(ITypeProcStmtMatch *s) override {
		s->getCond()->accept(m_this);
	}

	virtual void visitTypeProcStmtRepeat(ITypeProcStmtRepeat *s) override {
		s->getExpr()->accept(m_this);
		s->getBody()->accept(m_this);
	}

	virtual void visitTypeProcStmtRepeatWhile(ITypeProcStmtRepeatWhile *s) override {
		s->getExpr()->accept(m_this);
		s->getBody()->accept(m_this);
	}

	virtual void visitTypeProcStmtReturn(ITypeProcStmtReturn *s) override {
		if (s->getExpr()) {
			s->getExpr()->accept(m_this);
		}
	}

	virtual void visitTypeProcStmtScope(ITypeProcStmtScope *s) override {
		for (std::vector<ITypeProcStmtUP>::const_iterator
			it=s->getStatements().begin();
			it!=s->getStatements().end(); it++) {
			(*it)->accept(m_this);
		}
	}

	virtual void visitTypeProcStmtVarDecl(ITypeProcStmtVarDecl *s) override {
		s->getDataType()->accept(m_this);
		if (s->getInit()) {
			s->getInit()->accept(m_this);
		}
	}

	virtual void visitTypeProcStmtWhile(ITypeProcStmtWhile *s) override {
		s->getExpr()->accept(m_this);
		s->getBody()->accept(m_this);
	}

};

}
}
}


