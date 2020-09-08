#pragma once
#include "Gene.h"
#include "GeneShared.h"
class GeneFactory {
private:
	int instanceNumber;
	GeneFactory();
public:
	~GeneFactory();
	int getInstanceNumber();
	static GeneFactory *getInstance();
	Gene buildGene(GeneShared *g, char a, char b);
	GeneShared buildGeneShared(char * traitName, char * domTraitName, char * domTraitSymbol, char * recTraitName, char * recTraitSymbol, double * crossoverChance);
};