#include "Population.h"

Population::Population(){
	for (int i = 0; i < POPSIZE; i++) {
		phrase[i].setRandom();
	}
}

Phrase Population::getBestPhrase(bool removeBestPhrase){
	Phrase bestPhrase = phrase[0];
	int bestPhraseId = 0;
	for (int i = 0; i < POPSIZE; i++) {
		if( phrase[i].getFitness(answer) > bestPhrase.getFitness(answer)){
			bestPhrase = phrase[i];
			bestPhraseId = i;
		}
	}
	if(removeBestPhrase = true){
		char emptyLetters[PHRASELENGHT];
		for (int i = 0; i < PHRASELENGHT; i++) {
			emptyLetters[i] = 0;
		}
		phrase[bestPhraseId].setLetters(emptyLetters);
	}
	return bestPhrase;
}

void Population::evolve(){
	Phrase tempPop[POPSIZE];
	for (int i = 0; i < POPSIZE; i+=2) {
		tempPop[i] = getBestPhrase(true);
		tempPop[i+1] = tempPop[i];
	}
	for (int i = 0; i < POPSIZE; i++) {
		phrase[i] = tempPop[i];
	}
	Phrase bestPhrase = getBestPhrase();
	for (int i = 0; i < POPSIZE; i++) {
		phrase[i].crossWithPhrase(bestPhrase);
		phrase[i].mutate();
	}
}
