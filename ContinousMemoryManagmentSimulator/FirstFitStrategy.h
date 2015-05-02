#pragma once
#include "MemoryStrategyBase.h"
class FirstFitStrategy :
	public MemoryStrategyBase
{
public:
	FirstFitStrategy(MemoryManager* memMgr);
	~FirstFitStrategy();


	std::string getName() override;
	bool allocate(int size, int process) override;
};

