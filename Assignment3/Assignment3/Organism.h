#pragma once
#include <string>
#include <vector>
#include "Chromosome.h"
class Organism {
private:
	std::string genus;
	std::string species;
	std::string scientificName;
	std::string commonName;
	int geneCount;
	std::vector<Chromosome> chromosomes;
	std::vector<bool> hasGenes;
public:
	Organism();
	Organism(std::string genusParam, std::string speciesParam, std::string scientificNameParam, std::string commonNameParam, std::vector<Chromosome> chromosomeParam);
	~Organism();
	std::string getGenus();
	std::string getSpecies();
	std::string getScientificName();
	std::string getCommonName();
	int getChromosomeCount();
	Chromosome getChromosome(int index);
};