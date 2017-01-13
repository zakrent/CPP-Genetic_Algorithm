#include "Phrase.h"
#define POPSIZE 6000 //Must be an even number

class Population{
private:
	Phrase phrase[POPSIZE];
public:
	char answer[PHRASELENGHT+1] = "STRINGS ARE OBJECTS"; //so original
	//If you want to change phrase be sure to change phrase lenght in Phrase.h

	Population();
	void evolve();
	Phrase getBestPhrase(bool removeBestPhrase=false);
};
