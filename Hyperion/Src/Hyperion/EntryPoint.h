#pragma once

#ifdef HY_PLATFORM_WINDOWS

extern Hyperion::Application* Hyperion::CreateApplication();

int main(int argc, char** argv)
{
	Hyperion::Log::Init();
	HY_CORE_WARN("Initialized log!");
	const char* MyName = "Aadesh";
	HY_CORE_INFO("Hello {0}", MyName);

	auto app = Hyperion::CreateApplication();
	app->Run();
	delete app;
}

#endif