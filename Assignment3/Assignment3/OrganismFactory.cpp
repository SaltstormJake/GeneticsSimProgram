#include "OrganismFactory.h"

OrganismFactory::OrganismFactory() {

}

OrganismFactory::~OrganismFactory() {

}

int OrganismFactory::getInstanceNumber() {
	return this->instanceNumber;
}

OrganismFactory *OrganismFactory::getInstance() {
	static OrganismFactory *theInstance = NULL;
	static int counter = 1;
	if (theInstance == NULL) {
		theInstance = new OrganismFactory();
		theInstance->instanceNumber = counter;
		counter++;
	}
	return theInstance;
}

Organism OrganismFactory::buildOrganism(int parentNumber, std::vector<GeneShared> &shared, GeneticsSimDataParser *genetics) {
	ChromosomeFactory *chromosomeFactory = chromosomeFactory->getInstance();
	std::vector <Chromosome> chromosomes;
	char * strand1 = new char[10];
	char * strand2 = new char[10];
	std::vector<char> realStrand1;
	std::vector<char> realStrand2;
	if (parentNumber == 1)
		for (int i = 0; i < genetics->getChromosomeCount(); i++) {
			genetics->getP1Chromosome(strand1, strand2);
			//std::cout << strand1 << " " << strand2 << std::endl;
			Chromosome chromosome = chromosomeFactory->buildChromosome(shared, strand1, strand2);
			chromosomes.push_back(chromosome);
		}
	else if (parentNumber == 2)
		for (int i = 0; i < genetics->getChromosomeCount(); i++) {
			genetics->getP2Chromosome(strand1, strand2);
			//std::cout << strand1 << " " << strand2 << std::endl;
			Chromosome chromosome = chromosomeFactory->buildChromosome(shared, strand1, strand2);
			chromosomes.push_back(chromosome);
		}
	Organism o(genetics->getGenus(), genetics->getSpecies(), genetics->getScientificName(), genetics->getCommonName(), chromosomes);
	return o;
}
