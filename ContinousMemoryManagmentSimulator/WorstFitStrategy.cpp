#include "WorstFitStrategy.h"



WorstFitStrategy::WorstFitStrategy(MemoryManager* memMgr)
	: MemoryStrategyBase(memMgr)
{
}


WorstFitStrategy::~WorstFitStrategy()
{
}

std::string WorstFitStrategy::getName() {
	return "worst-fit";
}

bool WorstFitStrategy::allocate(int size, int process) {
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
				if (best->getSize() - size < remaing) {
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