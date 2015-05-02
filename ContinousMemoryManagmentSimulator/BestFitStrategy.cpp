#include "BestFitStrategy.h"


BestFitStrategy::BestFitStrategy(MemoryManager* memMgr)
	: MemoryStrategyBase(memMgr)
{
}


BestFitStrategy::~BestFitStrategy()
{
}

std::string BestFitStrategy::getName()  {
	return "best-fit";
}

bool BestFitStrategy::allocate(int size, int process) {
	std::vector<MemoryUnit*>::iterator it;
	MemoryUnit* best = NULL;
	std::vector<MemoryUnit*> toFree;
	for (it = this->memoryManager->getUnitsBegin(); it != this->memoryManager->getUnitsEnd(); it++) {
		if ((*it)->getFree() && (*it)->getSize() >= size) {
			if (best == NULL) {
				best = (*it);
			}
			else {
				int remaing = (*it)->getSize() - size;
				if (best->getSize() - size > remaing) {
					best = (*it);
				}
			}
		}
	}

	if (best != NULL) {
		this->memoryManager->allocate(best, size, process);
		return true;
	}

	return false;
}
