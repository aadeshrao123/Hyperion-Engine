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
		HY_INFO("ExampleLayer::Update");
	}

	void OnEvent(Hyperion::Event& event) override
	{
		HY_TRACE("{0}", event);
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