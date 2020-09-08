#pragma once

#include <vector>
#include "Chromosome.h"
#include <time.h>
class MendelSquare {
private:
	int trialNumber;
	int crossovers;
	struct Genotype;
	std::vector<Genotype> genotypes;
	std::vector<int> domTraitResults;
	std::vector<int> hetTraitResults;
	std::vector<int> recTraitResults;
public:
	MendelSquare();
	MendelSquare(int n);
	~MendelSquare();
	void newGeno(char a, char b, char c, char d, double cross);
	void runTrials();
	int getDomResult(int index);
	int getHetResult(int index);
	int getRecResult(int index);
	int getCrossovers();
};