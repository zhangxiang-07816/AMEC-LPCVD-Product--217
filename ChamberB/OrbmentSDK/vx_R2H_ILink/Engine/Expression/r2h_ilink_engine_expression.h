#ifndef R2H_ILINK_EXPRESSION_H_
#define R2H_ILINK_EXPRESSION_H_

#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <float.h>
#include <cmath>

extern "C"{
#include "../../Utility/regex/regex.h"
}

#include "../../r2h_ilink_env.h"
#include "r2h_ilink_engine_expression_def.h"
#include "../../r2h_ilink_data_type.h"
#include "../../r2h_ilink_error_code.h"
#include "../../Exception/r2h_ilink_exception.h"
#include "../../r2h_ilink_env.h"
#ifdef _WRS_VX_SMP
#include "../../vx_R2H_Task/IOControl/r2h_task_pdo_manager_def.h"
typedef bool (*PSEARCH_OBJECT)(void* pObjectManager, R2H_UINT32 objectIndex, R2H_TASK_PDO_AREA_T* pArea, R2H_TASK_PDO_INDEX_T *pIndex, R2H_BYTE** ptr);
#endif
namespace R2H_ILINK
{	
	class ExpressionElementRegex
	{
	public:
		ExpressionElementRegex(R2H_CONST_STRING regex, R2H_INT32 flag);
		virtual ~ExpressionElementRegex();
		R2H_INT32 Exec(R2H_CONST_STRING string, R2H_UINT32 nMatch, regmatch_t *pMatchPtr, R2H_INT32 flag);
	private:
		regex_t __pattern;
	};

	
	class ExpressionElement
	{
	public:
		ExpressionElement(EXPRESSION_ELEMENT_TYPE_T type);
		virtual ~ExpressionElement();
		inline EXPRESSION_ELEMENT_TYPE_T Type();
		virtual std::string ToString() const = 0;
	private:
		EXPRESSION_ELEMENT_TYPE_T __type;
	};
	EXPRESSION_ELEMENT_TYPE_T ExpressionElement::Type()
	{
		return __type;
	}
	
	class ImmediateOperand;

	class Operand : public ExpressionElement
	{
	public:
		Operand(EXPRESSION_ELEMENT_TYPE_T type);
		virtual ~Operand();
		virtual R2H_DOUBLE Value() const = 0;
		virtual std::string ToString() const = 0;
		virtual void Assign(Operand&) = 0;
		virtual void Assign(R2H_DOUBLE) = 0;
		friend ImmediateOperand operator+(const Operand& o1, const Operand& o2);
		friend ImmediateOperand operator-(const Operand& o1, const Operand& o2);
		friend ImmediateOperand operator*(const Operand& o1, const Operand& o2);
		friend ImmediateOperand operator/(const Operand& o1, const Operand& o2);
	};

	class ObjectReference : public Operand
	{
	public:
		explicit ObjectReference(R2H_UINT32 objectIndex);
		explicit ObjectReference(R2H_CONST_STRING string);
		ObjectReference(const ObjectReference&);
		ObjectReference& operator=(const ObjectReference&);
		virtual ~ObjectReference();
		virtual R2H_DOUBLE Value() const;
		virtual std::string ToString() const;
		
		inline R2H_UINT32 ObjectIndex() const;
		virtual void Assign(Operand&);
		virtual void Assign(R2H_DOUBLE);
		
		static R2H_INT32 OBJECT_INDEX_PATTERN(R2H_CONST_STRING string);
#ifdef _WRS_VX_SMP
		static PSEARCH_OBJECT SEARCH_OBJECT_CALLBACK;
#endif
	private:
		R2H_UINT32 __object_index;
		static ExpressionElementRegex  __PATTERN;
#ifdef _WRS_VX_SMP
		void __object_data_type_verify(const R2H_TASK_PDO_INDEX_T *pIndex) const;
		R2H_TASK_PDO_AREA_T __pdo_area;
		R2H_TASK_PDO_INDEX_T __pdo_index;
		R2H_BYTE* __pdo_pointer;
#endif
		//regex_t __pattern;
	};
	
	inline R2H_UINT32 ObjectReference::ObjectIndex() const
	{
		return __object_index;
	}

	class ImmediateOperand : public Operand
	{
	public:
		explicit ImmediateOperand(R2H_DOUBLE value);
		explicit ImmediateOperand(R2H_CONST_STRING string);
		ImmediateOperand(const Operand&);
		ImmediateOperand& operator=(const Operand&);
		virtual ~ImmediateOperand();
		virtual R2H_DOUBLE Value() const;
		virtual std::string ToString() const;
		virtual void Assign(Operand&);
		virtual void Assign(R2H_DOUBLE);
	private:
		R2H_DOUBLE __value;
		static ExpressionElementRegex  __PATTERN;
	};
	
	

	class Operator : public ExpressionElement
	{
	public:
		explicit Operator(R2H_CHAR ch);
		explicit Operator(OPERATOR_NAME_T name);
		Operator(const Operator&);
		Operator& operator=(const Operator&);
		virtual ~Operator();
		virtual std::string ToString() const;
		OPERATOR_NAME_T OperatorName() const;
		R2H_CHAR ToChar() const;
	private:
		OPERATOR_NAME_T __operator_name;
	};

	
	class EnvVariableReference : public Operand
	{
	public:
		EnvVariableReference(ENV_VARIABLE_T name, Context &context);
		EnvVariableReference(R2H_CONST_STRING string, Context &context);
		explicit EnvVariableReference(const EnvVariableReference&);
		EnvVariableReference& operator=(const EnvVariableReference&);
		virtual ~EnvVariableReference();
		virtual R2H_DOUBLE Value() const;
		virtual std::string ToString() const;

		virtual void Assign(Operand&);
		virtual void Assign(R2H_DOUBLE);
		
		inline ENV_VARIABLE_T Variable() const;
		inline R2H_UINT32 EnvUserIndex() const;

		static R2H_INT32 ENV_VARIABLE_PATTERN(R2H_CONST_STRING string);
	private:
		ENV_VARIABLE_T __variable_name;
		static ExpressionElementRegex  __PATTERN;
		R2H_UINT32 __env_user_index;
		Context& __context;
	};

	
	inline ENV_VARIABLE_T EnvVariableReference::Variable() const
	{
		return __variable_name;
	}

	inline R2H_UINT32 EnvVariableReference::EnvUserIndex() const
	{
		return __env_user_index;
	}

	class Expression;

	class Sprite : public Operand
	{
	public:
		Sprite(R2H_CONST_STRING in, Context &context, Sprite* pUpper);
		explicit Sprite(const Sprite&);
		virtual ~Sprite();
		virtual R2H_DOUBLE Value() const;
		virtual std::string ToString() const;
		virtual void Assign(Operand&);
		virtual void Assign(R2H_DOUBLE);
		inline R2H_INT32 Layer() const;
	private:
		std::vector<Expression*> __parameters;
		SPRITE_FUNCTION_T __function;
		void __clean();
		void __verify() const;
		const R2H_INT32 __layer;
		Sprite* pUpper;
	};

	R2H_INT32 Sprite::Layer() const
	{
		return __layer;
	}

	class Expression
	{
	public:
		Expression(const std::string in, Context &context, Sprite* pUpper = 0);
		Expression(R2H_CONST_STRING in, Context &context, Sprite* pUpper = 0);
		virtual ~Expression();

		R2H_DOUBLE Value(bool dividbyzeroException = false, R2H_DOUBLE defaultValue = 0.0) const;
		static R2H_INT32 CompareValue(R2H_DOUBLE a, R2H_DOUBLE b);
		std::string ToString() const;
		static bool FIND_NEXT_ELEMENT(R2H_CONST_STRING str, R2H_UINT32 start, R2H_UINT32 &next, EXPRESSION_ELEMENT_TYPE &type);
	private:
		Expression(const Expression&);
		Expression& operator=(const Expression&);
		
		std::vector<ExpressionElement*> __post_order_vector;
		std::vector<ExpressionElement*> __original_order_vector;
		mutable std::vector<double> __post_order_buffer;

		static inline bool __IS_AN_OPERATOR(R2H_CHAR ch);
		static bool __IS_AN_OPERATOR(R2H_UINT32 index, R2H_CONST_STRING str);
		static bool __FIND_NEXT_ELEMENT(R2H_CONST_STRING str, R2H_UINT32 start, R2H_UINT32 &next, EXPRESSION_ELEMENT_TYPE &type);


		inline R2H_INT32 __operator_index(R2H_CHAR op) const;

		void __verify() const;
		void __clean();

		static const R2H_CHAR __PRIORITY[7][7];
		static ExpressionElementRegex __OBJECT_REFERENCE_SEARCH_PATTERN;
		static ExpressionElementRegex __ENV_VARIABLE_REFERENCE_SEARCH_PATTERN;
		static ExpressionElementRegex __IMMEDIATE_OPERAND_SEARCH_PATTERN; 
		static ExpressionElementRegex __PATH_SEARCH_PATTERN;
		static ExpressionElementRegex __OPERATOR_SEARCH_PATTERN;
	};

	inline bool Expression::__IS_AN_OPERATOR(R2H_CHAR ch)
	{
		switch (ch)
		{
			case'+':
			case'-':
			case'*':
			case'/':
			case'(':
			case')':
			case'\0':
				return true;
			default:
				return false;
		}
	}

	inline R2H_INT32 Expression::__operator_index(R2H_CHAR ch) const
	{
		switch (ch)
		{
			case'+':return 0;
			case'-':return 1;
			case'*':return 2;
			case'/':return 3;
			case'(':return 4;
			case')':return 5;
			case'\0':return 6;
			default:return -1;
		}
	}

}

#endif

