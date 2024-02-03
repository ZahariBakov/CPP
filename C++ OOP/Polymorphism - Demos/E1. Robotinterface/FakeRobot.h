#pragma once

#include "RobotInterface.h"

class FakeRobot : public Robotnterface {
public:
	FakeRobot() = default;
	virtual ~FakeRobot() = default;

	void start() override;
	void stop() override;
	void doSomeWork() override;

private:

};

