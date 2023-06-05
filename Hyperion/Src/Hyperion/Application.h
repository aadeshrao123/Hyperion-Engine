#pragma once
#include "Hypch.h"

#include "Core.h"
#include "Events/Event.h"
#include "Hyperion/Events/ApplicationEvent.h"


#include "Window.h"


namespace Hyperion
{
	class HYPERION_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowsClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};

	//To be Defined in Client
	Application* CreateApplication();
};


