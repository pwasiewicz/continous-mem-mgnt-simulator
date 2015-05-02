
#include <iostream>
#include "MemoryManager.h"
#include "MemoryStrategyBase.h"
#include "BestFitStrategy.h"
#include "FirstFitStrategy.h"
#include "WorstFitStrategy.h"

std::vector<MemoryStrategyBase*> strategies;


void printStrategies() {
	for (int i = 0; i < strategies.size(); i++) {

		std::cout << strategies[i]->getName();
		if (i < strategies.size() - 1) {
			std::cout << ", ";
		}		
	}
}

MemoryStrategyBase* getStrategy(std::string name) {
	for (int i = 0; i < strategies.size(); i++) {
		if (strategies[i]->getName() == name) {
			return strategies[i];
		}
	}

	return NULL;
}

int main() {

	int memSize;
	int eventsNo;
	std::string strategyName;

	std::cout << "Memory size? "; std::cin >> memSize; std::cout << std::endl;


	MemoryManager memoryMgr(memSize);
	strategies.push_back(new BestFitStrategy(&memoryMgr));
	strategies.push_back(new WorstFitStrategy(&memoryMgr));
	strategies.push_back(new FirstFitStrategy(&memoryMgr));

	std::cout << "Strategy ("; printStrategies(); std::cout << ")? ";  std::cin >> strategyName;
	std::cout << "Allocations number? "; std::cin >> eventsNo; std::cout << std::endl;
	std::cout << "Enter allocations / deallocations: " << std::endl;


	MemoryStrategyBase* strategy = getStrategy(strategyName);
	if (strategy == NULL) {
		std::cout << "Invalid strategy";
		return 0;
	}

	std::cout << std::endl;

	for (int i = 0; i < eventsNo; i++) {
		int operation;
		int process;
		std::cin >> operation >> process;

		if (operation == 1) {
			int amount;
			std::cin >> amount;

			std::cout << "Allocating " << amount << " for process " << process << std::endl;
			strategy->allocate(amount, process);
		}
		else if (operation == 0) {
			std::cout << "Deallocating " << process << std::endl;
			strategy->free(process);
		}
		else {
			std::cout << "Invalid operation; available: 1 - allocate, 0 - dellacote";
			return 0;
		}
		std::cout << std::endl << memoryMgr << std::endl << std::endl;
	}


	return 0;
}