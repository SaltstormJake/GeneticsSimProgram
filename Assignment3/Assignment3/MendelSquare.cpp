#include "MendelSquare.h"


struct MendelSquare::Genotype {
	std::vector <char> fullGeno;
	double crossoverChance;
};
MendelSquare::MendelSquare() {
	crossovers = 0;
}

MendelSquare::MendelSquare(int n) {
	trialNumber = n;
	crossovers = 0;
}

MendelSquare::~MendelSquare() {

}

void MendelSquare::newGeno(char a, char b, char c, char d, double cross) {
	std::vector<char> fullGeno{ a,b,c,d };
	Genotype geno{ fullGeno, cross };
	genotypes.push_back(geno);
}

void MendelSquare::runTrials() {
	srand(time(NULL));
	for (int i = 0; i < trialNumber; i++) {
		for (int p = 0; p < genotypes.size(); p++) {
			domTraitResults.push_back(0);
			hetTraitResults.push_back(0);
			recTraitResults.push_back(0);
		}
		int select;
		int crossRand;
		bool crossover = false;
		for(int j = 0; j < genotypes.size(); j++){
			crossRand = rand() % 10000;
			if (crossRand <= genotypes[j].crossoverChance * 100) {
				std::swap(genotypes[j].fullGeno[0], genotypes[j].fullGeno[2]);
				std::swap(genotypes[j].fullGeno[1], genotypes[j].fullGeno[3]);
				crossover = true;
			}
		//for (int j = 0; j < genotypes.size(); j++) { //use this for individual allele swapping
		//	for (int k = 0; k < 2; k++) {
		//		crossRand = rand() % 100;
		//		if (crossRand <= genotypes[j].crossoverChance) {
		//			std::swap(genotypes[j].fullGeno[k], genotypes[j].fullGeno[k + 2]);
		//			crossover = true;
		//		}
		//	}
			char a = genotypes[j].fullGeno[0];
			char b = genotypes[j].fullGeno[1];
			char c = genotypes[j].fullGeno[2];
			char d = genotypes[j].fullGeno[3];
			if (isupper(a) && isupper(b) && isupper(c) && isupper(d)) //TTTT
				domTraitResults[j]++;
			else if (isupper(a) && isupper(b) && isupper(c) && !isupper(d)) { //TTTt
				select = rand() % 2;
				if (select == 0)
					domTraitResults[j]++;
				else
					hetTraitResults[j]++;
			}
			else if (isupper(a) && isupper(b) && !isupper(c) && isupper(d)) { //TTtT
				select = rand() % 2;
				if (select == 0)
					domTraitResults[j]++;
				else
					hetTraitResults[j]++;
			}
			else if (isupper(a) && isupper(b) && !isupper(c) && !isupper(d)) //TTtt
				hetTraitResults[j]++;
			else if (isupper(a) && !isupper(b) && isupper(c) && isupper(d)) { //TtTT
				select = rand() % 2;
				if (select == 0)
					domTraitResults[j]++;
				else
					hetTraitResults[j]++;
			}
			else if (isupper(a) && !isupper(b) && isupper(c) && !isupper(d)) { //TtTt
				select = rand() % 4;
				if (select == 0)
					domTraitResults[j]++;
				else if (select == 1)
					recTraitResults[j]++;
				else
					hetTraitResults[j]++;
			}
			else if (isupper(a) && !isupper(b) && !isupper(c) && isupper(d)) { //TttT
				select = rand() % 4;
				if (select == 0)
					domTraitResults[j]++;
				else if (select == 1)
					recTraitResults[j]++;
				else
					hetTraitResults[j]++;
			}
			else if (isupper(a) && !isupper(b) && !isupper(c) && !isupper(d)) { //Tttt
				select = rand() % 2;
				if (select == 0)
					hetTraitResults[j]++;
				else
					recTraitResults[j]++;
			}
			else if (!isupper(a) && isupper(b) && isupper(c) && isupper(d)) { //tTTT
				select = rand() % 2;
				if (select == 0)
					domTraitResults[j]++;
				else
					hetTraitResults[j]++;
			}
			else if (!isupper(a) && isupper(b) && isupper(c) && !isupper(d)) { //tTTt
				select = rand() % 4;
				if (select == 0)
					domTraitResults[j]++;
				else if (select == 1)
					recTraitResults[j]++;
				else
					hetTraitResults[j]++;
			}
			else if (!isupper(a) && isupper(b) && !isupper(c) && isupper(d)) { //tTtT
				select = rand() % 4;
				if (select == 0)
					domTraitResults[j]++;
				else if (select == 1)
					recTraitResults[j]++;
				else
					hetTraitResults[j]++;
			}
			else if (!isupper(a) && isupper(b) && !isupper(c) && !isupper(d)) { //tTtt
				select = rand() % 2;
				if (select == 0)
					hetTraitResults[j]++;
				else
					recTraitResults[j]++;
			}
			else if (!isupper(a) && !isupper(b) && isupper(c) && isupper(d)) //ttTT
				hetTraitResults[j]++;
			else if (!isupper(a) && !isupper(b) && isupper(c) && !isupper(d)) { //ttTt
				select = rand() % 2;
				if (select == 0)
					hetTraitResults[j]++;
				else
					recTraitResults[j]++;
			}
			else if (!isupper(a) && !isupper(b) && !isupper(c) && isupper(d)) { //tttT
				select = rand() % 2;
				if (select == 0)
					hetTraitResults[j]++;
				else
					recTraitResults[j]++;
			}
			else if (!isupper(a) && !isupper(b) && !isupper(c) && !isupper(d)) //tttt
				recTraitResults[j]++;
		}
		if (crossover)
			crossovers++;
	}
}

int MendelSquare::getDomResult(int index) {
	return domTraitResults[index];
}
int MendelSquare::getHetResult(int index) {
	return hetTraitResults[index];
}
int MendelSquare::getRecResult(int index) {
	return recTraitResults[index];
}
int MendelSquare::getCrossovers() {
	return crossovers;
}
