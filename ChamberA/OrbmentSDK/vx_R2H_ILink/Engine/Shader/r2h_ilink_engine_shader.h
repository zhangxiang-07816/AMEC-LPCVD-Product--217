/*
 * r2h_ilink_engine_shader.h
 *
 *  Created on: 2020-4-17
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_ENGINE_SHADER_H_
#define R2H_ILINK_ENGINE_SHADER_H_

#include "r2h_ilink_engine_shader_def.h"
#include "../Expression/r2h_ilink_engine_expression.h"
#include "../../Utility/cJSON/cJSON.h"

namespace R2H_ILINK
{	
	class Shader
	{
	public:
		Shader(R2H_CONST_STRING operand, R2H_CONST_STRING express, Context& context);
		Shader(const cJSON* pObject, Context& context);
		virtual ~Shader();
		std::string ToString() const;
		void Update();
	private:
		Shader(const Shader&);
		Operand* __operand;
		Expression* __expression;
		void __clean();
	};

	typedef std::vector<Shader*> ShaderVector;
}



#endif /* R2H_ILINK_ENGINE_SHADER_H_ */
