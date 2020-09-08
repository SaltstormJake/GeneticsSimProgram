#pragma once
#include "Organism.h"
#include "Chromosome.h"
#include "ChromosomeFactory.h"
#include "GeneticsSimDataParser.h"
#include <string>
class OrganismFactory {
private:
	int instanceNumber;
	OrganismFactory();
public:
	~OrganismFactory();
	int getInstanceNumber();
	static OrganismFactory *getInstance();
	Organism buildOrganism(int parentNumber, std::vector<GeneShared> &shared, GeneticsSimDataParser *genetics);
};