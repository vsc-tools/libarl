/*
 * Context.h
 *
 *  Created on: Apr 16, 2022
 *      Author: mballance
 */

#pragma once
#include <unordered_map>
#include "arl/IContext.h"
#include "vsc/impl/ContextDelegator.h"

namespace arl {

class Context : public virtual IContext, public vsc::ContextDelegator {
public:
	Context(vsc::IContext *ctxt);

	virtual ~Context();

	virtual IModelFieldAction *buildModelAction(
			IDataTypeAction 	*t,
			const std::string	&name) override;

	virtual IModelFieldComponent *buildModelComponent(
			IDataTypeComponent 	*t,
			const std::string	&name) override;

	virtual IDataTypeAction *findDataTypeAction(const std::string &) override;

	virtual IDataTypeAction *mkDataTypeAction(const std::string &name) override;

	virtual bool addDataTypeAction(IDataTypeAction *t) override;

	virtual IDataTypeFunction *findDataTypeFunction(const std::string &name) override;

	virtual IDataTypeFunction *mkDataTypeFunction(
			const std::string		&name,
			vsc::IDataType			*rtype,
			bool					own_rtype) override;

	virtual bool addDataTypeFunction(IDataTypeFunction *f) override;

	virtual IDataTypeFunctionParamDecl *mkDataTypeFunctionParamDecl(
			const std::string		&name,
			vsc::IDataType			*type,
			bool					own,
			vsc::ITypeExpr			*init) override;

	virtual IDataTypeActivityParallel *mkDataTypeActivityParallel() override;

	virtual IDataTypeActivitySchedule *mkDataTypeActivitySchedule() override;

	virtual IDataTypeActivitySequence *mkDataTypeActivitySequence() override;

	virtual IDataTypeActivityTraverse *mkDataTypeActivityTraverse(
			vsc::ITypeExprFieldRef	*target,
			vsc::ITypeConstraint	*with_c) override;

	virtual IDataTypeComponent *findDataTypeComponent(const std::string &name) override;

	virtual IDataTypeComponent *mkDataTypeComponent(const std::string &name) override;

	virtual bool addDataTypeComponent(IDataTypeComponent *t) override;

	virtual IDataTypeFlowObj *findDataTypeFlowObj(
			const std::string 	&name,
			FlowObjKindE		kind) override;

	virtual IDataTypeFlowObj *mkDataTypeFlowObj(
			const std::string 	&name,
			FlowObjKindE		kind) override;

	virtual bool addDataTypeFlowObj(IDataTypeFlowObj *t) override;

	virtual IModelActivityParallel *mkModelActivityParallel() override;

	virtual IModelActivitySchedule *mkModelActivitySchedule() override;

	virtual IModelActivitySequence *mkModelActivitySequence() override;

	virtual IModelActivityTraverse *mkModelActivityTraverse(
			IModelFieldAction		*target,
			vsc::IModelConstraint	*with_c) override;

	virtual IModelEvaluator *mkModelEvaluator() override;

	virtual IModelFieldAction *mkModelFieldActionRoot(
			const std::string		&name,
			IDataTypeAction			*type) override;

	virtual IModelFieldAction *mkModelFieldActionType(
			vsc::ITypeField			*type) override;

	virtual IModelFieldComponent *mkModelFieldComponentRoot(
			IDataTypeComponent		*type,
			const std::string		&name) override;

	virtual IModelFieldComponent *mkModelFieldComponentType(
			vsc::ITypeField         *type) override;

	virtual IModelFieldExecutor *mkModelFieldExecutor(
			vsc::ITypeField			*type) override;

	virtual IModelFieldExecutorClaim *mkModelFieldExecutorClaim(
			vsc::ITypeField			*type) override;

	virtual IModelFieldPool *mkModelFieldPoolType(
			vsc::ITypeField			*type) override;

	virtual IPoolBindDirective *mkPoolBindDirective(
			PoolBindKind			kind,
			vsc::ITypeExprFieldRef	*pool,
			vsc::ITypeExprFieldRef	*target) override;

	virtual ITypeFieldActivity *mkTypeFieldActivity(
			const std::string		&name,
			IDataTypeActivity		*type,
			bool					owned) override;

	virtual ITypeFieldClaim *mkTypeFieldClaim(
			const std::string		&name,
			vsc::IDataType			*type,
			bool					is_lock) override;

	virtual ITypeFieldExecutor *mkTypeFieldExecutor(
			const std::string		&name,
			vsc::IDataType			*type,
			bool					owned) override;

	virtual ITypeFieldExecutorClaim *mkTypeFieldExecutorClaim(
			const std::string		&name,
			vsc::IDataType			*type,
			bool					owned) override;

	virtual ITypeFieldInOut *mkTypeFieldInOut(
			const std::string		&name,
			vsc::IDataType			*type,
			bool					is_input) override;

	virtual ITypeFieldPool *mkTypeFieldPool(
			const std::string		&name,
			vsc::IDataType			*type,
			bool					own,
			vsc::TypeFieldAttr		attr,
			int32_t					decl_size) override;

	virtual ITypeProcStmtBreak *mkTypeProcStmtBreak() override;

	virtual ITypeProcStmtContinue *mkTypeProcStmtContinue() override;

	virtual ITypeProcStmtForeach *mkTypeProcStmtForeach(
			vsc::ITypeExpr		*target,
			ITypeProcStmt		*body) override;

	virtual ITypeProcStmtIfElse *mkTypeProcStmtIfElse(
			vsc::ITypeExpr		*cond,
			ITypeProcStmt		*true_s,
			ITypeProcStmt		*false_s) override;
	
	virtual ITypeProcStmtMatch *mkTypeProcStmtMatch(
			vsc::ITypeExpr		*cond) override;

	virtual ITypeProcStmtRepeat *mkTypeProcStmtRepeat(
			vsc::ITypeExpr		*cond,
			ITypeProcStmt		*body) override;

	virtual ITypeProcStmtRepeatWhile *mkTypeProcStmtRepeatWhile(
			vsc::ITypeExpr		*cond,
			ITypeProcStmt		*body) override;

	virtual ITypeProcStmtReturn *mkTypeProcStmtReturn(
			vsc::ITypeExpr		*expr) override;

	virtual ITypeProcStmtScope *mkTypeProcStmtScope() override;

	virtual ITypeProcStmtVarDecl *mkTypeProcStmtVarDecl(
			const std::string	 &name,
			vsc::IDataType		 *type,
			bool				 own,
			vsc::ITypeExpr		 *init) override;

	virtual ITypeProcStmtWhile *mkTypeProcStmtWhile(
			vsc::ITypeExpr		*cond,
			ITypeProcStmt		*body) override;

private:
	using FlowObjMapT=std::unordered_map<std::string,IDataTypeFlowObjUP>;

private:
	std::unordered_map<std::string, IDataTypeActionUP>			m_action_type_m;
	std::unordered_map<std::string, IDataTypeComponentUP>		m_component_type_m;
	std::unordered_map<std::string, IDataTypeFunctionUP>		m_function_type_m;
	std::unordered_map<FlowObjKindE, FlowObjMapT>				m_flowobj_kind_m;

};

} /* namespace arl */

