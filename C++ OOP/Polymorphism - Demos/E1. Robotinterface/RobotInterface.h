#pragma once

#include <iostream>

class Robotnterface {
public:
	Robotnterface() = default;
	virtual ~Robotnterface() = default;

	virtual void start();
	virtual void stop();
	virtual void doSomeWork();

	bool isRunning() const;

protected:
	bool _isRunning = false;

private:

};
