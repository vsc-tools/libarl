/*
 * Context.h
 *
 *  Created on: Apr 16, 2022
 *      Author: mballance
 */

#pragma once
#include <unordered_map>
#include "arl/IContext.h"

namespace arl {

class Context : public IContext {
public:
	Context(vsc::IContext *ctxt);

	virtual ~Context();

	virtual vsc::IModelField *buildModelAction(
			IDataTypeAction 	*t,
			const std::string	&name) override;

	virtual vsc::IModelField *buildModelComponent(
			IDataTypeComponent 	*t,
			const std::string	&name) override;

	virtual IDataTypeAction *findDataTypeAction(const std::string &name) override;

	virtual IDataTypeAction *mkDataTypeAction(const std::string &name) override;

	virtual bool addDataTypeAction(IDataTypeAction *t) override;

	virtual IDataTypeComponent *findDataTypeComponent(const std::string &name) override;

	virtual IDataTypeComponent *mkDataTypeComponent(const std::string &name) override;

	virtual bool addDataTypeComponent(IDataTypeComponent *t) override;

	virtual IDataTypeFlowObj *findDataTypeFlowObj(const std::string &name) override;

	virtual IDataTypeFlowObj *mkDataTypeFlowObj(
			const std::string 	&name,
			FlowObjKindE		kind) override;

	virtual bool addDataTypeFlowObj(IDataTypeFlowObj *t) override;

	virtual IModelEvaluator *mkModelEvaluator() override;

	virtual ITypeActivityStmtTraverseType *mkTypeActivityStmtTraverseType(
			IDataTypeAction			*action_t,
			vsc::ITypeConstraint	*constraint) override;

	/****************************************************************
	 * Implementation of vsc::IContext
	 ****************************************************************/
	virtual vsc::IModelFieldRoot *buildModelField(
			vsc::IDataTypeStruct			*dt,
			const std::string		&name) override;

	virtual vsc::ICompoundSolver *mkCompoundSolver() override;

	virtual vsc::IDataTypeInt *findDataTypeInt(
			bool			is_signed,
			int32_t			width) override;

	/**
	 * Returns a new datatype. The expectation is that
	 * it will be subsequently added to the context
	 */
	virtual vsc::IDataTypeInt *mkDataTypeInt(
			bool			is_signed,
			int32_t			width) override;

	virtual bool addDataTypeInt(vsc::IDataTypeInt *t) override;

	virtual vsc::IDataTypeStruct *findDataTypeStruct(const std::string &name) override;

	virtual vsc::IDataTypeStruct *mkDataTypeStruct(const std::string &name) override;

	virtual bool addDataTypeStruct(vsc::IDataTypeStruct *t) override;

	virtual vsc::IModelConstraintBlock *mkModelConstraintBlock(
			const std::string &name) override;

	virtual vsc::IModelConstraintExpr *mkModelConstraintExpr(
			vsc::IModelExpr		*expr) override;

	virtual vsc::IModelExprBin *mkModelExprBin(
			vsc::IModelExpr		*lhs,
			vsc::BinOp			op,
			vsc::IModelExpr		*rhs) override;

	virtual vsc::IModelExprFieldRef *mkModelExprFieldRef(
			vsc::IModelField		*field) override;

	virtual vsc::IModelExprVal *mkModelExprVal(vsc::IModelVal *) override;

	virtual vsc::IModelFieldRoot *mkModelFieldRoot(
			vsc::IDataType 			*type,
			const std::string	&name) override;

	virtual vsc::IModelFieldType *mkModelFieldType(
			vsc::ITypeField			*type) override;

	virtual vsc::IModelVal *mkModelVal() override;

	virtual vsc::IRandomizer *mkRandomizer(
			vsc::ISolverFactory		*solver_factory,
			vsc::IRandState			*randstate) override;


	virtual vsc::IRandState *mkRandState(uint32_t seed) override;

	virtual vsc::ITask *mkTask(vsc::TaskE id) override;

	virtual vsc::ITypeExprBin *mkTypeExprBin(
			vsc::ITypeExpr		*lhs,
			vsc::BinOp			op,
			vsc::ITypeExpr		*rhs) override;

	virtual vsc::ITypeConstraintBlock *mkTypeConstraintBlock(const std::string &name) override;

	virtual vsc::ITypeConstraintExpr *mkTypeConstraintExpr(vsc::ITypeExpr *) override;

	virtual vsc::ITypeConstraintScope *mkTypeConstraintScope() override;

	virtual vsc::ITypeExprFieldRef *mkTypeExprFieldRef() override;

	virtual vsc::ITypeExprVal *mkTypeExprVal(const vsc::IModelVal *) override;

	virtual vsc::ITypeField *mkTypeField(
			const std::string		&name,
			vsc::IDataType				*dtype,
			vsc::TypeFieldAttr			attr,
			vsc::IModelVal				*init) override;


private:
	vsc::IContext			*m_ctxt;
	std::unordered_map<std::string, IDataTypeActionUP>			m_action_type_m;
	std::unordered_map<std::string, IDataTypeComponentUP>		m_component_type_m;
	std::unordered_map<std::string, IDataTypeFlowObjUP>			m_flowobj_type_m;

};

} /* namespace arl */

