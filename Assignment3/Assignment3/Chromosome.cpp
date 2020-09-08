#include "Chromosome.h"
#include "GeneFactory.h"
#include <iostream>
Chromosome::Chromosome() {

}

Chromosome::Chromosome(char * a, char * b) {
	genotype1 = a;
	genotype2 = b;
}

Chromosome::Chromosome(std::vector<Gene> g, std::string a, std::string b) {
	genotype1 = a;
	genotype2 = b;
	genes = g;
}

Chromosome::~Chromosome() {

}

std::string Chromosome::getGeno1() {
	return genotype1;
}

std::string Chromosome::getGeno2() {
	return genotype2;
}

std::string Chromosome::getFullGeno() {
	std::string fullGeno = genotype1 + genotype2;
	return fullGeno;
}

Gene Chromosome::getGene(int index) {
	return genes[index];
}

void Chromosome::addGene(Gene g) {
	genes.push_back(g);
}

int Chromosome::getGeneNum() {
	return genes.size();
}