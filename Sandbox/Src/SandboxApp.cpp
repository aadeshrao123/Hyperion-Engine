#include "Hyperion.h"

class Sandbox : public Hyperion::Application
{
	public:
		Sandbox()
		{

		}
		~Sandbox()
		{

		}
};

Hyperion::Application* Hyperion::CreateApplication()
{
	return new Sandbox();
}