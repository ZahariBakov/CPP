#include "FakeRobot.h"

void FakeRobot::start() {
	Robotnterface::start();
	std::cout << "Fake robot is starting instantly " << std::endl;
}

void FakeRobot::stop() {
	Robotnterface::stop();
	std::cout << "fake robot stopping" << std::endl;
}

void FakeRobot::doSomeWork() {
	Robotnterface::doSomeWork();
	std::cout << "Fake robot doing some work..." << std::endl;
}
