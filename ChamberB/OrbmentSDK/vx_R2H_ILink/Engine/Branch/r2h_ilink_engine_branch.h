/*
 * r2h_ilink_engine_branch.h
 *
 *  Created on: 2020-4-18
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_ENGINE_BRANCH_H_
#define R2H_ILINK_ENGINE_BRANCH_H_

#include "r2h_ilink_engine_branch_def.h"
#include "../Expression/r2h_ilink_engine_expression.h"
#include "../Event/r2h_ilink_engine_event_trigger.h"
#include "../../Utility/cJSON/cJSON.h"
#include "../Shader/r2h_ilink_engine_shader.h"
#include <vector>
#include <map>

namespace R2H_ILINK
{
	class Branch
	{
	public:
		Branch(R2H_UINT32 target, R2H_CONST_STRING trigger, const EventStorage &globalEvents, EventStorage &localEvents, const EventClock &clock, Context& context);
		Branch(const cJSON* pBranchObject, const EventStorage &globalEvents, EventStorage &localEvents, const EventClock &clock, Context& context);
		virtual ~Branch();
		std::string ToString(R2H_UINT32 tabs = 0) const;
		void PushPostShader(const cJSON* pShaderObject, Context& context);
		void PushPostShader(R2H_CONST_STRING operand, R2H_CONST_STRING express, Context& context);
		void PopPostShader();
		void RemovePostShader(R2H_UINT32 index);
		void InserPostShader(R2H_UINT32 index, const cJSON* pShaderObject, Context& context);
		void InserPostShader(R2H_UINT32 index, R2H_CONST_STRING operand, R2H_CONST_STRING express, Context& context);
		void ClearPostShader();
		
		inline R2H_UINT32 Target() const;
		bool Eval(bool updatePostShaders, R2H_UINT32& target);
		void UpdatePostShaders();
		inline bool CheckEventReference(const Event*) const;
	private:
		Branch(const Branch&);
		R2H_UINT32 __target;
		EventTrigger* __event_trigger;
		ShaderVector __post_shaders;
		void __clean();
	};
	
	inline R2H_UINT32 Branch::Target() const
	{
		return __target;
	}

	inline bool Branch:: CheckEventReference(const Event* p) const
	{
		return __event_trigger == 0 ? false : __event_trigger->Search(p);
	}

	typedef std::vector<Branch*> BranchVector;
}


#endif /* R2H_ILINK_ENGINE_BRANCH_H_ */
