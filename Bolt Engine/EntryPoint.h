#pragma once

#ifdef BOLT_PLATFORM_WINDOWS // Checks we are on Windows

extern Bolt::Application* Bolt::CreateApplication();// Some function defined somewhere else that will return a Bolt application pointer (In our case the GameLayer)

int main(int argc, char** argv)
{

	// Runs the application created by the GameLayer
	auto app = Bolt::CreateApplication();
	app->Run();
	delete app;

}
#endif