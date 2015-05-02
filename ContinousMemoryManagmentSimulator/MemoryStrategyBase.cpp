#include "MemoryStrategyBase.h"



MemoryStrategyBase::MemoryStrategyBase(MemoryManager* memoryManager)
{
	this->memoryManager = memoryManager;
}


MemoryStrategyBase::~MemoryStrategyBase()
{
}

void MemoryStrategyBase::free(int process) {
	std::vector<MemoryUnit*>::iterator it;
	std::vector<MemoryUnit*> toFree;
	for (it = this->memoryManager->getUnitsBegin(); it != this->memoryManager->getUnitsEnd(); it++) {
		if (!(*it)->getFree() && (*it)->getProcess() == process) {
			toFree.push_back(*it);
		}
	}

	for (int i = 0; i < toFree.size(); i++) {
		this->memoryManager->free(toFree[i]);
	}
}
