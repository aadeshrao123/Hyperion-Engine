#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Hyperion
{
	class HYPERION_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be Defined in Client
	Application* CreateApplication();
};


