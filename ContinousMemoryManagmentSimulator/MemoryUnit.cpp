#include "MemoryUnit.h"
#include <sstream>


MemoryUnit::MemoryUnit()
{
}

MemoryUnit::MemoryUnit(int size, bool isFree, int assigment)
{
	this->size = size;
	this->isFree = isFree;
	this->assigment = assigment;
}


MemoryUnit::~MemoryUnit()
{
}

int MemoryUnit::getSize() const
{
	return this->size;;
}

bool MemoryUnit::getFree() const
{
	return this->isFree;
}

int MemoryUnit::getProcess() const
{
	return this->assigment;
}

std::string MemoryUnit::toString()
{
	std::ostringstream stringStream;

	if (this->getFree()) {
		stringStream << "Free " << this->size;
	}
	else {
		stringStream << "P" << this->assigment << " " << this->size;
	}

	return stringStream.str();
}
