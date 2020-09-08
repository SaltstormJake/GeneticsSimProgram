#pragma once
#include "Gene.h"
#include "Chromosome.h"
class ChromosomeFactory {
private:
	int instanceNumber;
	ChromosomeFactory();
public:
	~ChromosomeFactory();
	int getInstanceNumber();
	static ChromosomeFactory *getInstance();
	Chromosome buildChromosome(std::vector<GeneShared> &g, char * a, char * b);
};