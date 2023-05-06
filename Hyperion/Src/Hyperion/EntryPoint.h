#pragma once
#ifdef HY_PLATFORM_WINDOWS

extern Hyperion::Application* Hyperion::CreateApplication();

int main(int argc, char** argv)
{
	printf("Hyperion Engine\n");
	auto app = Hyperion::CreateApplication();
	app->Run();
	delete app;
}

#endif