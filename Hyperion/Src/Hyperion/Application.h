#pragma once
#include "Core.h"

#include "Window.h"
#include "Hyperion/LayerStack.h"
#include "Hyperion/Events/Event.h"
#include "Hyperion/Events/ApplicationEvent.h"


namespace Hyperion
{
	class HYPERION_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		bool OnWindowsClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To be Defined in Client
	Application* CreateApplication();
};


