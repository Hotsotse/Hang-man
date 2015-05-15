/*
 * multiline comment tho
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int TRIES=0;
int MAX_TRIES=5;
string letter;

string words[] =
{
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

int main(){

	int rand = (random() %10);
	string word = words[rand];

	cout << "Welcome to hangman mang!" << endl;
	cout << "Random word has been generated! Word is " << word.length() << " letters long!" << endl;
	while (TRIES < 5){
		cout << "Guess a letter, you get 5 tries =)" << endl;
		cin >> letter;
		if (word.find(letter)){
			cout << "Ya b0ss" << endl;
		} else {
			cout << "Nope" << endl;
			TRIES++;
		}
	}

	return 0;

}
