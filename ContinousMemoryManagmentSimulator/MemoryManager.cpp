#include "MemoryManager.h"



MemoryManager::MemoryManager(int size)
{
	MemoryUnit * startUnit = new MemoryUnit(size, true, -1);
	this->units.push_back(startUnit);
}


MemoryManager::~MemoryManager()
{
	for (int i = 0; i < this->units.size(); i++) {
		MemoryUnit* u = this->units[i];
		delete u;
	}
}

std::vector<MemoryUnit*>::iterator MemoryManager::getUnitsBegin()
{
	return this->units.begin();
}

std::vector<MemoryUnit*>::iterator MemoryManager::getUnitsEnd()
{
	return this->units.end();
}

void MemoryManager::allocate(MemoryUnit * unit, int size, int process)
{
	int elemIndex = -1;
	for (int i = 0; i < this->units.size(); i++) {
		if (this->units[i] == unit) {
			elemIndex = i;
		}
	}

	if (elemIndex == -1) {
		throw "Cannot find specified unit.";
	}

	MemoryUnit* toAllocate = this->units[elemIndex];
	std::vector<MemoryUnit*>::iterator replacedUnitIt = this->units.begin() + elemIndex;

	if (toAllocate->getSize() < size) {
		throw "Memory unit to small.";
	}

	if (!toAllocate->getFree()) {
		throw "Memory unit to small.";
	}

	int freeSpace = toAllocate->getSize() - size;

	MemoryUnit* newUnit = new MemoryUnit(size, false, process);
	replacedUnitIt = this->units.insert(replacedUnitIt + 1, newUnit) - 1;

	if (freeSpace > 0) {
		MemoryUnit* freeUnity = new MemoryUnit(freeSpace, true, -1);
		replacedUnitIt = this->units.insert(replacedUnitIt + 2, freeUnity) - 2;
	}

	this->units.erase(replacedUnitIt);
}

void MemoryManager::free(MemoryUnit * unit)
{
	int elemIndex = -1;
	for (int i = 0; i < this->units.size(); i++) {
		if (this->units[i] == unit) {
			elemIndex = i;
		}
	}

	if (elemIndex == -1) {
		throw "Cannot find specified unit.";
	}

	if (unit->getFree()) {
		throw "Memory unit already free.";
	}

	std::vector<MemoryUnit*>::iterator toDeleteIt = this->units.begin() + elemIndex;
	int deletedSize = unit->getSize();
	toDeleteIt = this->units.erase(toDeleteIt);
	delete unit;

	if (toDeleteIt != this->units.end()) {
		if ((*toDeleteIt)->getFree()) {
			MemoryUnit* u = (*toDeleteIt);
			deletedSize += u->getSize();
			toDeleteIt=this->units.erase(toDeleteIt);
			delete u;
		}
	}

	if ((toDeleteIt) > this->units.begin()) {
		std::vector<MemoryUnit*>::iterator prev = toDeleteIt - 1;
		if ((*prev)->getFree()) {
			MemoryUnit* u = (*prev);
			deletedSize += u->getSize();
			toDeleteIt = this->units.erase(prev);
			delete u;
		}
	}

	MemoryUnit * newUnit = new MemoryUnit(deletedSize, true, -1);

	if (this->units.size() == 0) {
		this->units.push_back(newUnit);
	}
	else {
		this->units.insert(toDeleteIt, newUnit);
	}
}

std::ostream& operator<<(std::ostream& os, const MemoryManager& dt)
{
	std::vector < std::string > v;
	for (int i = 0; i < dt.units.size(); i++) {
		std::string s = dt.units[i]->toString();
		v.push_back(s);
	}
	
	if (v.size() == 0) return os;

	int bestSize = v[0].length();
	for (int i = 1; i < v.size(); i++) {
		if (v[i].length() > bestSize) {
			bestSize = v[i].length();
		}
	}

	for (int i = 0; i < bestSize + 4; i++) os << "=";
	
	for (int m = 0; m < v.size(); m++) {
		os << std::endl << "|";
		for (int i = 1; i < bestSize + 3; i++) os << " ";
		os << "|" << std::endl << "| ";		 
		std::string toWrite = v[m];
		os << toWrite;
		int left = 2 + toWrite.length();
		for (int i = left; i < bestSize + 3; i++) os << " ";
		os << "|" << std::endl << "|";;

		for (int i = 1; i < bestSize + 3; i++) os << " ";
		os << "|" << std::endl;

		if (m < v.size() - 1) {
			for (int i = 0; i < bestSize + 4; i++) os << "-";
		}
	}

	for (int i = 0; i < bestSize + 4; i++) os << "=";

	return os;
}
