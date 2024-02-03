#pragma once

#include <thread>

#include "RobotInterface.h"

class RealRobot : public Robotnterface {
public:
	RealRobot() = default;
	virtual~RealRobot() = default;

	void start() override;
	void stop() override;
	void doSomeWork() override;

private:

};

