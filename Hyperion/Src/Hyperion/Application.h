#pragma once
#include "Core.h"

#include "Window.h"
#include "Hyperion/LayerStack.h"
#include "Hyperion/Events/Event.h"
#include "Hyperion/Events/ApplicationEvent.h"
#include "ImGui/ImGuiLayer.h"


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

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowsClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};

	//To be Defined in Client
	Application* CreateApplication();
};


