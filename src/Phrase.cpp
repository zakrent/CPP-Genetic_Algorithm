#include "Phrase.h"

std::random_device generator;
std::uniform_int_distribution<int> genomeDistribution(32,90);
std::uniform_int_distribution<int> crossDistribution(0,1);
std::uniform_int_distribution<int> mutationDistribution(0,10000);

void Phrase::setRandom(){
	for (int i = 0; i < PHRASELENGHT; i++) {
		letter[i]=genomeDistribution(generator);
	}
}

void Phrase::mutate(){
	for (int i = 0; i < PHRASELENGHT; i++) {
		if(mutationDistribution(generator) < MUTATIONRATE){
			letter[i]=genomeDistribution(generator);
		}
	}
}

void Phrase::setLetters(char _letter[PHRASELENGHT]){
	for (int i = 0; i < PHRASELENGHT; i++) {
		letter[i]=_letter[i];
	}
}

void Phrase::crossWithPhrase(Phrase Phrase){
	for (int i = 0; i < PHRASELENGHT; i++) {
		if(crossDistribution(generator)==0){
			letter[i]=Phrase.letter[i];
		}
	}
}

int Phrase::getFitness(char answer[PHRASELENGHT]){
	int score=0;
	for (int i = 0; i < PHRASELENGHT; i++) {
		if (letter[i] == answer[i]) {
			score++;
		}
	}
	return score;
}

string Phrase::dumpLetters(){
	string letterCombination;
	for (int i = 0; i < PHRASELENGHT; i++) {
		letterCombination.push_back(letter[i]);
	}
	return letterCombination;
}
