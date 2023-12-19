#include "Application.h"
#include "Logger.h"

void Application::someAwesomeMethod() {
	//Logger::getInstance().print("Is this really working?!?", LogTarget::STDOUT);
	Logger::getInstance().print("Is this really working?!?", LogTarget::FILE);
}