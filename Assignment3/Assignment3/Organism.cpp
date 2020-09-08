#include "Organism.h"
#include "GeneShared.h"
#include "Chromosome.h"
Organism::Organism() {

}
Organism::Organism(std::string genusParam, std::string speciesParam, std::string scientificNameParam, std::string commonNameParam, std::vector<Chromosome> chromosomeParam) {
	genus = genusParam;
	species = speciesParam;
	scientificName = scientificNameParam;
	commonName = commonNameParam;
	chromosomes = chromosomeParam;
}
Organism::~Organism() {

}
std::string Organism::getGenus() {
	return genus;
}
std::string Organism::getSpecies() {
	return species;
}
std::string Organism::getScientificName() {
	return scientificName;
}
std::string Organism::getCommonName() {
	return commonName;
}
int Organism::getChromosomeCount() {
	return chromosomes.size();
}
Chromosome Organism::getChromosome(int index) {
	return chromosomes[index];
}
