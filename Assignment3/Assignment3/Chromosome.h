#pragma once
#include <string>
#include <vector>
#include "Gene.h"
#include "GeneFactory.h"

class Chromosome {
private:
	std::string genotype1;
	std::string genotype2;
	std::vector <Gene> genes;
public:
	Chromosome();
	Chromosome(char * a, char * b);
	Chromosome(std::vector<Gene> g, std::string a, std::string b);
	~Chromosome();
	std::string getGeno1();
	std::string getGeno2();
	std::string getFullGeno();
	Gene getGene(int index);
	void addGene(Gene g);
	int getGeneNum();
};