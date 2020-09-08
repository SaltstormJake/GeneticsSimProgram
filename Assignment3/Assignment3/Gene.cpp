#include "Gene.h"

Gene::Gene() {

}
Gene::Gene(GeneShared *shared, char a, char b) {
	masterTraits = shared;
	allele1 = a;
	allele2 = b;
}
Gene::~Gene() {
}
char Gene::getAllele1() {
	return allele1;
}
char Gene::getAllele2() {
	return allele2;
}
std::string Gene::getTraitName() {
	return masterTraits->getTraitName();
}
std::string Gene::getDomTraitName() {
	return masterTraits->getDomTraitName();
}
char Gene::getDomTraitSymbol() {
	return masterTraits->getDomTraitSymbol();
}
std::string Gene::getRecTraitName() {
	return masterTraits->getRecTraitName();
}
char Gene::getRecTraitSymbol() {
	return masterTraits->getRecTraitSymbol();
}
double Gene::getCrossoverChance() {
	return masterTraits->getCrossoverChance();
}