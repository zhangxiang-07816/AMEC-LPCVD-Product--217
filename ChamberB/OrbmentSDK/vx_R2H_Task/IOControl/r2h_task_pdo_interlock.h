/*
 * r2h_task_pdo_interlock.h
 *
 *  Created on: Feb 9, 2022
 *      Author: HaihangRen
 */

#ifndef R2H_TASK_PDO_INTERLOCK_H_
#define R2H_TASK_PDO_INTERLOCK_H_

#include <vector>
#include <assert.h>
#include "r2h_task_pdo_interlock_def.h"
#include "../r2h_task_data_type.h"

using namespace std;

class R2H_Task_PDOInterlockExpression;

class R2H_Task_PDOInterlockElement
{
private:
	const R2H_TASK_PDO_INTERLOCK_LOGIC_ELEMENT_TYPE_T __type;
	const R2H_Task_PDOInterlockExpression* __root_ptr;
	const R2H_INT32 __layer;
public:
	R2H_Task_PDOInterlockElement(R2H_TASK_PDO_INTERLOCK_LOGIC_ELEMENT_TYPE_T type, R2H_Task_PDOInterlockExpression *pRoot);
	virtual ~R2H_Task_PDOInterlockElement();
	R2H_TASK_PDO_INTERLOCK_LOGIC_ELEMENT_TYPE_T Type();
	R2H_INT32 Layer();
	virtual bool Value() const = 0;
};
inline R2H_TASK_PDO_INTERLOCK_LOGIC_ELEMENT_TYPE_T R2H_Task_PDOInterlockElement::Type(){return __type;}
inline R2H_INT32 R2H_Task_PDOInterlockElement::Layer(){return __layer;}

class R2H_Task_PDOInterlockOperand : public R2H_Task_PDOInterlockElement
{
public:
	R2H_Task_PDOInterlockOperand(R2H_UINT16* objectDataBuffer, R2H_UINT32 offsetInBit, R2H_Task_PDOInterlockExpression *pRoot);
	virtual ~R2H_Task_PDOInterlockOperand();
	virtual bool Value() const;
private:
	const R2H_UINT16* __object_data_buffer;
	const R2H_UINT32 __offset_in_bit;	
};

class R2H_Task_PDOInterlockExpression : public R2H_Task_PDOInterlockElement
{
public:
	R2H_Task_PDOInterlockExpression(R2H_TASK_PDO_INTERLOCK_LOGIC_OPERATOR_T op, R2H_Task_PDOInterlockExpression *pRoot);
	virtual ~R2H_Task_PDOInterlockExpression();
	virtual bool Value() const;
	R2H_TASK_PDO_INTERLOCK_LOGIC_OPERATOR_T LogicOperator();
	vector<R2H_Task_PDOInterlockElement*>& LogicElements();
	//void Clear();
private:
	vector<R2H_Task_PDOInterlockElement*> __logic_elements;
	const R2H_TASK_PDO_INTERLOCK_LOGIC_OPERATOR_T __logic_operator;	
};

inline R2H_TASK_PDO_INTERLOCK_LOGIC_OPERATOR_T R2H_Task_PDOInterlockExpression::LogicOperator(){return __logic_operator;}
inline vector<R2H_Task_PDOInterlockElement*>& R2H_Task_PDOInterlockExpression::LogicElements(){return __logic_elements;}

class R2H_Task_PDOInterlockTarget
{
public:
	R2H_Task_PDOInterlockTarget(R2H_UINT16* pRxBitArea);
	virtual ~R2H_Task_PDOInterlockTarget();
	vector<R2H_UINT32>& TargetOffsetInBit();
	void ResetTargetBits() const;
	//void SetTargetBits();
private:
	R2H_UINT16* __rx_bit_area_ptr;
	vector<R2H_UINT32> __target_offset_in_bit;
};

inline vector<R2H_UINT32>& R2H_Task_PDOInterlockTarget::TargetOffsetInBit(){return __target_offset_in_bit;}

class R2H_Task_PDOInterlockLogic
{
public:
	R2H_Task_PDOInterlockLogic(const R2H_Task_PDOInterlockTarget *pTarget, 
			const R2H_Task_PDOInterlockExpression *pStatement);
	virtual ~R2H_Task_PDOInterlockLogic();
	bool Execute() const;
private:
	R2H_Task_PDOInterlockLogic(const R2H_Task_PDOInterlockLogic&);
	const R2H_Task_PDOInterlockTarget *__target_ptr;
	const R2H_Task_PDOInterlockExpression *__statement_ptr;
};



#endif /* R2H_TASK_PDO_INTERLOCK_H_ */
