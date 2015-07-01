#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string randomWord(){
	string words[] = {
		"India",
		"Pakistan",
		"Nepal",
		"Malaysia",
		"Philippines",
		"Australia",
		"Iran",
		"Ethiopia",
		"Oman",
		"Indonesia"
	};
	string word = words[rand() % 9];
	return word;
}

int letterFill(char guess, string secretword, string &guessword){
    int i;
    int matches=0;
    int len=secretword.length();

    for (i = 0; i< len; i++)
    {
        // Did we already match this letter in a previous guess?
        if (guess == guessword[i]) return 0;

        // Is the guess in the secret word?
        if (guess == secretword[i]){
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}

int main(){
	int tries = 0;
    int maxTries = 6;
	string letter = "";
	string word = randomWord();
	string unknown(word.length(), '_');
	cout << "Welcome to hangman mang!" << endl;
	cout << "Random word has been generated! Word is " << word.length() << " letters long!" << endl;
	while (tries < maxTries){
		cout << unknown;
        char letter = cin.get();
		if (letterFill(letter, word, unknown) == 0){
			cout << "Could not find " << letter << " in the word." << endl;
			tries++;
		}
		else {
			cout << "Found letter! " << endl;
		}

		cout << "Guess a letter, you have " << tries << " left." << endl;

		if (word == unknown)
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
			break;
		}
	}
	cout << endl << "Sorry, you lose...you've been hanged." << endl;
	cout << "The word was : " << word << endl;
	}
	cin.ignore();

	return 0;
}

