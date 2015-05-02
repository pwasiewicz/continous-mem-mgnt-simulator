#pragma once

#include "MemoryStrategyBase.h"
#include <string>

class WorstFitStrategy
	: public MemoryStrategyBase
{
public:
	WorstFitStrategy(MemoryManager* memMgr);
	~WorstFitStrategy();

	virtual std::string getName();
	virtual bool allocate(int size, int process);
};

