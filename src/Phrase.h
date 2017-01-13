#include <random>
#include <string>
#define PHRASELENGHT 19
#define MUTATIONRATE 100

using std::string;

class Phrase{
private:
	char letter[PHRASELENGHT];
public:
	void setRandom();
	void setLetters(char _letter[PHRASELENGHT]);
	void crossWithPhrase(Phrase Phrase);
	string dumpLetters();
	int getFitness(char answer[PHRASELENGHT+1]);
	void mutate();
};
