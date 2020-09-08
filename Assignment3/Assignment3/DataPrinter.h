#pragma once

#include <iostream>
#include <string>
#include "Organism.h"
#include "Chromosome.h"
#include "Gene.h"
class DataPrinter {
private:
	int offspringNum;
	Organism parent1;
	Organism parent2;
public:
	DataPrinter();
	DataPrinter(Organism p1, Organism p2);
	~DataPrinter();
	std::string masterGenes();
	std::string parent1Info();
	std::string parent2Info();
	void setOffspringNum(int n);
	std::string squareResults();
	void setParents(Organism p1, Organism p2);
};