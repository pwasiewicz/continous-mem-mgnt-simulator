#pragma once

#include<string>

class MemoryUnit
{
private:
	int size;
	bool isFree;
	int assigment;
public:
	MemoryUnit();
	MemoryUnit(int size, bool isFree, int assigment);
	~MemoryUnit();

	int getSize() const;
	bool getFree() const;
	int getProcess() const;

	std::string toString();
};

