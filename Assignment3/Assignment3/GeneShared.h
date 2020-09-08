#pragma once
#include <string>
class GeneShared {
private:
	std::string traitName;
	std::string domTraitName;
	char domTraitSymbol;
	std::string recTraitName;
	char recTraitSymbol;
	double crossoverChance;

public:
	GeneShared();
	GeneShared(char * traitNameParam, char * domTraitNameParam, char domTraitSymbolParam, char * recTraitNameParam, char recTraitSymbolParam, double * crossoverChanceParam);
	~GeneShared();
	std::string getTraitName();
	std::string getDomTraitName();
	char getDomTraitSymbol();
	std::string getRecTraitName();
	char getRecTraitSymbol();
	double getCrossoverChance();
};