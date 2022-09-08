/*
 * r2h_ilink_engine_step.h
 *
 *  Created on: 2020-4-22
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_ENGINE_STEP_H_
#define R2H_ILINK_ENGINE_STEP_H_

#include <string>
#include <vector>
#include <map>
#include "r2h_ilink_engine_step_def.h"
#include "../Shader/r2h_ilink_engine_shader.h"
#include "../Branch/r2h_ilink_engine_branch.h"
#include "../Event/r2h_ilink_engine_event.h"

namespace R2H_ILINK
{
	class Step
	{
	public:
		Step(const cJSON* pStepObject, const EventStorage &globalEvents, const EventClock& clock, Context& context, R2H_UINT32 stepSlots);
		virtual ~Step();
		std::string ToString(R2H_UINT32 tabs = 0) const;
		inline R2H_UINT32 Index() const;
		void Render();
		bool Next(bool updatePostShaders, R2H_UINT32& nextStep);
		bool CheckEventReference(const Event*p) const;
		static R2H_UINT32 STEP_INDEX(const cJSON* pStepObject);
		void ResetAllEvents();
	private:
		Step(const Step&);
		R2H_UINT32 __index;
		ShaderVector __shaders;
		BranchVector __branchs;
		EventStorage __local_events;
		void __clean();
	};

	inline R2H_UINT32 Step::Index() const
	{
		return __index;
	}

	typedef std::vector<Step*> StepVector;
}

#endif /* R2H_ILINK_ENGINE_STEP_H_ */
