#pragma once

#include "Hyperion/Layer.h"

namespace Hyperion
{

	class HYPERION_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		float m_Time = 0.f;

	};
}