#include "ChromosomeFactory.h"
#include <iostream>
ChromosomeFactory::ChromosomeFactory() {

}

ChromosomeFactory::~ChromosomeFactory() {

}

int ChromosomeFactory::getInstanceNumber() {
	return this->instanceNumber;
}

ChromosomeFactory *ChromosomeFactory::getInstance() {
	static ChromosomeFactory *theInstance = NULL;
	static int counter = 1;
	if (theInstance == NULL) {
		theInstance = new ChromosomeFactory();
		theInstance->instanceNumber = counter;
		counter++;
	}
	return theInstance;
}

Chromosome ChromosomeFactory::buildChromosome(std::vector<GeneShared> &g, char * a, char * b) {
	std::vector<char> strand1;
	std::vector<char> strand2;
	for (int i = 0; i < strlen(a) + 1; i++) {
		if (!(a[i] == ' '))
			strand1.push_back(a[i]);
	}
	for (int i = 0; i < strlen(b) + 1; i++) {
		if (!(b[i] == ' '))
			strand2.push_back(b[i]);
	}
	for (int i = 0; i < strand1.size(); i++) {
		std::cout << strand1[i] << strand2[i] << "\n";
	}
	std::string s1(strand1.begin(), strand1.end());
	std::string s2(strand2.begin(), strand2.end());
	s1.pop_back();
	s2.pop_back();
	std::vector <Gene> genes;
	GeneFactory *geneFactory = geneFactory->getInstance();
	for (int i = 0; i < g.size(); i++) {
		for (int j = 0; j < s1.size(); j++) {
			if ((s1[j] == g[i].getDomTraitSymbol()) || (s1[j] == g[i].getRecTraitSymbol())) {
				genes.push_back(geneFactory->buildGene(&g[i], s1[j], s2[j]));
			}
		}
	}
	Chromosome c(genes, s1, s2);
	return c;
}
