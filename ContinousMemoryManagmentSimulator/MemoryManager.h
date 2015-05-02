#pragma once

#include<vector>
#include"MemoryUnit.h"
#include<iostream>

class MemoryManager
{
private:
	std::vector<MemoryUnit*> units;
public:
	MemoryManager(int size);
	~MemoryManager();

	std::vector<MemoryUnit*>::iterator getUnitsBegin();
	std::vector<MemoryUnit*>::iterator getUnitsEnd();

	void allocate(MemoryUnit* unit, int size, int process);
	void free(MemoryUnit* unit);

	friend std::ostream& operator<<(std::ostream& os, const MemoryManager& dt);
};

