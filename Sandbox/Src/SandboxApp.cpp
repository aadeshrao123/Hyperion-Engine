#include "Hyperion.h"

class ExampleLayer : public Hyperion::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//HY_INFO("ExampleLayer::Update");
		if (Hyperion::Input::IsKeyPressed(HY_KEY_TAB))
		{
			HY_TRACE("Tab key is pressed (poll)!");
		}
	}

	void OnEvent(Hyperion::Event& event) override
	{
		if (event.GetEventType() == Hyperion::EventType::KeyPressed)
		{
			Hyperion::KeyPressedEvent& e = (Hyperion::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HY_KEY_TAB)
				HY_TRACE("Tab key is pressed (event)!");
			HY_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class Sandbox : public Hyperion::Application
{
	public:
		Sandbox()
		{
			PushLayer(new ExampleLayer());
			PushOverlay(new Hyperion::ImGuiLayer());
		}
		~Sandbox()
		{

		}
};

Hyperion::Application* Hyperion::CreateApplication()
{
	return new Sandbox();
}