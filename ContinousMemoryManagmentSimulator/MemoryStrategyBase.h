#pragma once

#include<string>
#include "MemoryManager.h"
class MemoryStrategyBase
{
protected:
	MemoryManager* memoryManager;

public:
	MemoryStrategyBase(MemoryManager* memoryManager);
	~MemoryStrategyBase();

	virtual std::string getName() { return ""; }
	virtual bool allocate(int size, int process) { return false; };
	virtual void free(int process);
};

