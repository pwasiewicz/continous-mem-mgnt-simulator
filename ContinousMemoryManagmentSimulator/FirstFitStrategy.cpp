#include "FirstFitStrategy.h"



FirstFitStrategy::FirstFitStrategy(MemoryManager* memMgr)
	: MemoryStrategyBase(memMgr)
{
}


FirstFitStrategy::~FirstFitStrategy()
{
}

std::string FirstFitStrategy::getName() {
	return "first-fit";
}


bool FirstFitStrategy::allocate(int size, int process) {
	std::vector<MemoryUnit*>::iterator it;
	MemoryUnit* best = NULL;
	std::vector<MemoryUnit*> toFree;
	for (it = this->memoryManager->getUnitsBegin(); it != this->memoryManager->getUnitsEnd(); it++) {
		if ((*it)->getFree() && (*it)->getSize() >= size) {
			best = *it;
			break;
		}
	}

	if (best != NULL) {
		this->memoryManager->allocate(best, size, process);
		return true;
	}
	else {
		return false;
	}
}
