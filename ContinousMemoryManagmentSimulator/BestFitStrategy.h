#pragma once
#include "MemoryStrategyBase.h"
class BestFitStrategy :
	public MemoryStrategyBase
{
public:
	BestFitStrategy(MemoryManager* memMgr);
	~BestFitStrategy();

	std::string getName() override; 
	bool allocate(int size, int process) override;
};

