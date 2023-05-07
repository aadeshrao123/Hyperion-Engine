#include "Application.h"

#include "Hyperion/Events/ApplicationEvent.h"
#include "Hyperion/Log.h"

namespace Hyperion
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1920, 1080);
		if (e.IsInCategory(EventCategoryApplication))
		{
			printf("EventCategoryApplication");
			HY_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			printf("EventCategoryInput");
			HY_TRACE(e);
		}
		while (true);
	}

}