#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>

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

int main(){
	int letterFill(string, string, string&);
	int TRIES = 0;
	int MAX_TRIES = 5;
	string letter = "";
	string word = randomWord();
	string unknown(word.length(), '*');
	cout << "Welcome to hangman mang!" << endl;
	cout << "Random word has been generated! Word is " << word.length() << " letters long!" << endl;
	while (TRIES < 6){
		cout << unknown;
		getline(cin, letter);
		if (letterFill(letter, word, unknown) == 0){
			cout << "Could not find " << letter << " in the word." << endl;
			TRIES++;
		}
		else {
			cout << "Found letter! " << endl;
		}

		cout << "Guess a letter, you have " << TRIES << " left." << endl;

		if (word == unknown)
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
			break;
		}
	}
	if (TRIES == MAX_TRIES)
	{
		cout << "\nSorry, you lose...you've been hanged." << endl;
		cout << "The word was : " << word << endl;
	}
	cin.ignore();
	cin.get();

	return 0;
}
