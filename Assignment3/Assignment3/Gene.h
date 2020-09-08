#pragma once
#include "GeneShared.h"
class Gene {
private:
	GeneShared *masterTraits;
	char allele1;
	char allele2;
public:
	Gene();
	Gene(GeneShared *shared, char a, char b);
	~Gene();
	char getAllele1();
	char getAllele2();
	std::string getTraitName();
	std::string getDomTraitName();
	char getDomTraitSymbol();
	std::string getRecTraitName();
	char getRecTraitSymbol();
	double getCrossoverChance();
};