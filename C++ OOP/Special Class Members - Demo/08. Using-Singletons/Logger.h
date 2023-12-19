#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

enum class LogTarget {
	STDOUT,
	FILE
};

class Logger {
public:
	/* This function creates an instance of singleton Logger.
	It is lazy and thread safe. */
	static Logger& getInstance() {
		static Logger app;
		return app;
	}

	//Copy/Move constructor is disallowed
	Logger(const Logger& other) = delete;
	Logger(Logger&& other) = delete;

	//Disallowing copy/move assigment operator
	Logger& operator=(const Logger& other) = delete;
	Logger& operator=(Logger&& other) = delete;

	void print(const std::string& data, LogTarget target = LogTarget::STDOUT);

private:
	Logger();
	~Logger() = default;

	std::ofstream _outFile;
};

#endif // !LOGGER_H
