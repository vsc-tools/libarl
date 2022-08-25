/*
 * DataTypeFlowObj.cpp
 *
 *  Created on: Apr 16, 2022
 *      Author: mballance
 */

#include "DataTypeFlowObj.h"

namespace arl {

DataTypeFlowObj::DataTypeFlowObj(
		const std::string	&name,
		FlowObjKindE 		kind) : DataTypeStruct(name), m_kind(kind) {
	// TODO Auto-generated constructor stub

}

DataTypeFlowObj::~DataTypeFlowObj() {
	// TODO Auto-generated destructor stub
}

} /* namespace arl */
