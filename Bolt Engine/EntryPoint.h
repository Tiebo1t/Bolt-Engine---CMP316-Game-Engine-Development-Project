#pragma once

#ifdef BOLT_PLATFORM_WINDOWS // Checks we are on Windows

// To be implemented in the client
extern Bolt::Application* Bolt::CreateApplication();// Some function defined somewhere else that will return a Bolt application pointer (In our case the GameLayer)

int main(int argc, char** argv)
{

	auto app = Bolt::CreateApplication();
	app->Run();
	delete app;

}
#endif