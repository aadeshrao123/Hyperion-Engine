#pragma once

#include "Hyperion/Layer.h"

#include "Hyperion/Events/ApplicationEvent.h"
#include "Hyperion/Events/KeyEvent.h"
#include "Hyperion/Events/MouseEvent.h"

namespace Hyperion
{

	class HYPERION_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:

		float m_Time = 0.f;

	};
}