#include <iostream>
#include <vector>
#include <string>
#include <iostream>

#include "Defines.h"

constexpr auto ALLOCATE_CMD = "Allocate";
constexpr auto DEALLOCATE_CMD = "Deallocate";
constexpr auto IDLE_CMD = "IDLE";

size_t getIndexFromCommand(const std::string& command) {
	int index = 0;
	std::istringstream istr(command);
	std::string emptyPlaceholder;
	istr >> emptyPlaceholder >> index;

	return index;
}

ErrorCode handleAllocate(std::vector<int *>& memory, size_t index) {
	if (0 > index || index >= memory.size()) {
		return ErrorCode::INDEX_OUT_OF_BOUND;
	 }

	if (memory[index]) {
		return ErrorCode::MEMORY_LEAK;
	}

	memory[index] = new int;
	return ErrorCode::EXECUTE_SUCCESS;
}

ErrorCode handleDeallocate(std::vector<int *>& memory, size_t index) {
	if (0 > index || index >= memory.size()) {
		return ErrorCode::INDEX_OUT_OF_BOUND;
	}

	if (!memory[index]) {
		return ErrorCode::DOUBLE_FREE;
	}

	delete memory[index];
	memory[index] = nullptr;
	return ErrorCode::EXECUTE_SUCCESS;
}

ErrorCode executeCommand(const std::string& command,
						 std::vector<int*>& memory) {
	if (command == IDLE_CMD) {
		return ErrorCode::EXECUTE_IDLE;
	}
	
	if (std::string::npos != command.find(ALLOCATE_CMD)) {
		const size_t index = getIndexFromCommand(command);
		return handleAllocate(memory, index);
	}
	
	if (std::string::npos != command.find(DEALLOCATE_CMD)) {
		const size_t index = getIndexFromCommand(command);
		return handleDeallocate(memory, index);
	}

	std::cerr << "received invalid Command:" << command;
	return ErrorCode::EXECUTE_IDLE;
}

void printResult(const ErrorCode     errorCode,
    const std::string& command) {
	std::cout << command << " - ";

	switch (errorCode) {
	case EXECUTE_SUCCESS:
		std::cout << "success";
		break;
	case EXECUTE_IDLE:
		std::cout << "this exam is a piece of cake! Where is the OOP already?!?";
		break;
	case MEMORY_LEAK:
		std::cout << "memory leak prevented, will not make allocation";
		break;
	case DOUBLE_FREE:
		std::cout << "system crash prevented, will skip this deallocation";
		break;
	case INDEX_OUT_OF_BOUND:
		std::cout << "out of bound";
		break;
	default:
		std::cerr << "Received invalid errorCode: " << errorCode;
		break;
	}
}
