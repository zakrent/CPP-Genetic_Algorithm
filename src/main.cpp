#include "Population.h"
#include <iostream>

int main(){
	Population mainPop;
	int bestFitness = 0;
	for (int i = 0; i < 1000; i++) {
		bestFitness = mainPop.getBestPhrase().getFitness(mainPop.answer);
		std::cout<<mainPop.getBestPhrase().dumpLetters()<<" Generation: "<<i<<" Fitness: "<< bestFitness <<std::endl;
		if(bestFitness == PHRASELENGHT){
			break;
		}
		mainPop.evolve();
	}
}
