#include "DataPrinter.h"
#include "MendelSquare.h"
DataPrinter::DataPrinter() {

}

DataPrinter::DataPrinter(Organism p1, Organism p2) {
	parent1 = p1;
	parent2 = p2;
}

DataPrinter::~DataPrinter() {

}

std::string DataPrinter::masterGenes() {
	std::string master;
	for (int i = 0; i < parent1.getChromosomeCount(); i++) {
		master += "Chromosome ";
		master += std::to_string(i + 1);
		master += "\r\n";
		for (int j = 0; j < parent1.getChromosome(i).getGeneNum(); j++) {
			master += "   TraitName: ";
			master += parent1.getChromosome(i).getGene(j).getTraitName();
			master += "\r\n      Dominant Name: ";
			master += parent1.getChromosome(i).getGene(j).getDomTraitName();
			master += " (";
			master += parent1.getChromosome(i).getGene(j).getDomTraitSymbol();
			master += ")\r\n      Recessive Name: ";
			master += parent1.getChromosome(i).getGene(j).getRecTraitName();
			master += " (";
			master += parent1.getChromosome(i).getGene(j).getDomTraitSymbol();
			master += ")\r\n      Chance of Crossover: ";
			
			master += std::to_string(parent1.getChromosome(i).getGene(j).getCrossoverChance());
			master += "\r\n";
		}
	}
	return master;
}

std::string DataPrinter::parent1Info() {
	std::string info;
	for (int i = 0; i < parent1.getChromosomeCount(); i++) {
		for (int j = 0; j < parent1.getChromosome(i).getGeneNum(); j++) {
			char a = parent1.getChromosome(i).getGene(j).getAllele1();
			char b = parent1.getChromosome(i).getGene(j).getAllele2();
			info += a;
			info += b;
			info += " - ";
			if ((a == parent1.getChromosome(i).getGene(j).getDomTraitSymbol()) && (b == parent1.getChromosome(i).getGene(j).getDomTraitSymbol())) {
				info += "Dominant ";
				info += parent1.getChromosome(i).getGene(j).getDomTraitName();
			}
			else if ((a == parent1.getChromosome(i).getGene(j).getRecTraitSymbol()) && (b == parent1.getChromosome(i).getGene(j).getRecTraitSymbol())) {
				info += "Recessive ";
				info += parent1.getChromosome(i).getGene(j).getRecTraitName();
			}
			else {
				info += "Heterozygous ";
				info += parent1.getChromosome(i).getGene(j).getDomTraitName();
			}
			info += "\r\n";
		}
	}
	return info;
}

std::string DataPrinter::parent2Info() {
	std::string info;
	for (int i = 0; i < parent2.getChromosomeCount(); i++) {
		for (int j = 0; j < parent2.getChromosome(i).getGeneNum(); j++) {
			char a = parent2.getChromosome(i).getGene(j).getAllele1();
			char b = parent2.getChromosome(i).getGene(j).getAllele2();
			info += a;
			info += b;
			info += " - ";
			if ((a == parent2.getChromosome(i).getGene(j).getDomTraitSymbol()) && (b == parent2.getChromosome(i).getGene(j).getDomTraitSymbol())) {
				info += "Dominant ";
				info += parent2.getChromosome(i).getGene(j).getDomTraitName();
			}
			else if ((a == parent2.getChromosome(i).getGene(j).getRecTraitSymbol()) && (b == parent2.getChromosome(i).getGene(j).getRecTraitSymbol())) {
				info += "Recessive ";
				info += parent2.getChromosome(i).getGene(j).getRecTraitName();
			}
			else {
				info += "Heterozygous ";
				info += parent2.getChromosome(i).getGene(j).getDomTraitName();
			}
			info += "\r\n";
		}
	}
	return info;
}

void DataPrinter::setOffspringNum(int n) {
	offspringNum = n;
}

void DataPrinter::setParents(Organism p1, Organism p2) {
	parent1 = p1;
	parent2 = p2;
}
std::string DataPrinter::squareResults() {
	MendelSquare square(offspringNum);
	for (int i = 0; i < parent1.getChromosomeCount(); i++) {
		for (int j = 0; j < parent1.getChromosome(i).getGeneNum(); j++) {
			square.newGeno(parent1.getChromosome(i).getGene(j).getAllele1(), parent1.getChromosome(i).getGene(j).getAllele2(), parent2.getChromosome(i).getGene(j).getAllele1(), parent2.getChromosome(i).getGene(j).getAllele2(), parent1.getChromosome(i).getGene(j).getCrossoverChance());
		}
	}
	square.runTrials();
	std::string results;
	results += "A total of ";
	results += std::to_string(square.getCrossovers());
	results += " organisms had at least one crossover gene.";
	int index = 0;
	for (int i = 0; i < parent1.getChromosomeCount(); i++) {
		for (int j = 0; j < parent1.getChromosome(i).getGeneNum(); j++) {
			results += "\r\nGene: ";
			results += parent1.getChromosome(i).getGene(j).getTraitName();
			results += "\r\n\t";
			results += std::to_string(square.getDomResult(index));
			results += " homozygous dominant (";
			results += parent1.getChromosome(i).getGene(j).getDomTraitName();
			results += " ";
			results += parent1.getChromosome(i).getGene(j).getDomTraitSymbol();
			results += parent1.getChromosome(i).getGene(j).getDomTraitSymbol();
			results += ")\r\n\t";
			results += std::to_string(square.getHetResult(index));
			results += " heterozygous dominant (";
			results += parent1.getChromosome(i).getGene(j).getDomTraitName();
			results += " ";
			results += parent1.getChromosome(i).getGene(j).getDomTraitSymbol();
			results += parent1.getChromosome(i).getGene(j).getRecTraitSymbol();
			results += ")\r\n\t";
			results += std::to_string(square.getRecResult(index));
			results += " homozygous recessive (";
			results += parent1.getChromosome(i).getGene(j).getRecTraitName();
			results += " ";
			results += parent1.getChromosome(i).getGene(j).getRecTraitSymbol();
			results += parent1.getChromosome(i).getGene(j).getRecTraitSymbol();
			results += ")\r\n";
			
			index++;
		}
	}
	return results;
}