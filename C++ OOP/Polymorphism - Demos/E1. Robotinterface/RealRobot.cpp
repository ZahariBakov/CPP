#include "RealRobot.h"

void RealRobot::start() {
	Robotnterface::start();
	std::cout << "The real robot is taking 3 seconds to actually start" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
}

void RealRobot::stop() {
	Robotnterface::stop();
	std::cout << "Real robot stopping" << std::endl;
}

void RealRobot::doSomeWork() {
	Robotnterface::doSomeWork();
	std::cout << "real robot doing some work" << std::endl;
}
