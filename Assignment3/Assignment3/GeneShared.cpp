#include "GeneShared.h"

GeneShared::GeneShared() {

}
GeneShared::GeneShared(char * traitNameParam, char * domTraitNameParam, char domTraitSymbolParam, char * recTraitNameParam, char recTraitSymbolParam, double * crossoverChanceParam) {
	traitName = traitNameParam;
	domTraitName = domTraitNameParam;
	domTraitSymbol = domTraitSymbolParam;
	recTraitName = recTraitNameParam;
	recTraitSymbol = recTraitSymbolParam;
	crossoverChance = *crossoverChanceParam;
}
GeneShared::~GeneShared() {

}
std::string GeneShared::getTraitName() {
	return traitName;
}
std::string GeneShared::getDomTraitName() {
	return domTraitName;
}
char GeneShared::getDomTraitSymbol() {
	return domTraitSymbol;
}
std::string GeneShared::getRecTraitName() {
	return recTraitName;
}
char GeneShared::getRecTraitSymbol() {
	return recTraitSymbol;
}
double GeneShared::getCrossoverChance() {
	return crossoverChance;
}