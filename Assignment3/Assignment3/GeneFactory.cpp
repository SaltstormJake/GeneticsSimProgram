#include "GeneFactory.h"

GeneFactory::GeneFactory() {

}

GeneFactory::~GeneFactory() {

}

int GeneFactory::getInstanceNumber() {
	return this->instanceNumber;
}

GeneFactory *GeneFactory::getInstance() {
	static GeneFactory *theInstance = NULL;
	static int counter = 1;
	if (theInstance == NULL) {
		theInstance = new GeneFactory();
		theInstance->instanceNumber = counter;
		counter++;
	}
	return theInstance;
}

Gene GeneFactory::buildGene(GeneShared *g, char a, char b) {
	Gene gene(g, a, b);
	return gene;
}

GeneShared GeneFactory::buildGeneShared(char * traitName, char * domTraitName, char * domTraitSymbol, char * recTraitName, char *recTraitSymbol, double * crossoverChance) {
	GeneShared gene(traitName, domTraitName, domTraitSymbol[0], recTraitName, recTraitSymbol[0], crossoverChance);
	return gene;
}