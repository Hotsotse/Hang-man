#include <iostream>
#include <string>
#include <random>

using namespace std;
int random(int a, int b){
    thread_local mt19937 eng{random_device{}()};
    uniform_int_distribution<int> dist(a, b);
    return dist(eng);
}

string randomWord() {
	string words[] = {
		"Afghanistan",
		"Albania",
		"Algeria",
		"Andorra",
		"Angola",
		"Argentina",
		"Armenia",
		"Aruba",
		"Australia",
		"Austria",
		"Azerbaijan",
		"Bahamas",
		"Bahrain",
		"Bangladesh",
		"Barbados",
		"Belarus",
		"Belgium",
		"Belize",
		"Benin",
		"Bermuda",
		"Bhutan",
		"Bolivia",
		"Bosnia",
		"Botswana",
		"Brazil",
		"Bulgaria",
		"Burundi",
		"Cambodia",
		"Cameroon",
		"Canada",
		"Chad",
		"Chile",
		"China",
		"Colombia",
		"Comoros",
		"Croatia",
		"Cuba",
		"Curacao",
		"Cyprus",
		"Denmark",
		"Djibouti",
		"Dominica",
		"Ecuador",
		"Egypt",
		"Eritrea",
		"Estonia",
		"Ethiopia",
		"Fiji",
		"Finland",
		"France",
		"Gabon",
		"Gambia",
		"Georgia",
		"Germany",
		"Ghana",
		"Gibraltar",
		"Greece",
		"Greenland",
		"Grenada",
		"Guam",
		"Guatemala",
		"Guinea",
		"Guyana",
		"Haiti",
		"Honduras",
		"Hungary",
		"Iceland",
		"India",
		"Indonesia",
		"Iraq",
		"Ireland",
		"Israel",
		"Italy",
		"Jamaica",
		"Japan",
		"Jordan",
		"Kazakhstan",
		"Kenya",
		"Kiribati",
		"Kosovo",
		"Kuwait",
		"Latvia",
		"Lebanon",
		"Lesotho",
		"Liberia",
		"Libya",
		"Liechtenstein",
		"Lithuania",
		"Luxembourg",
		"Macedonia",
		"Madagascar",
		"Malawi",
		"Malaysia",
		"Maldives",
		"Mali",
		"Malta",
		"Mauritania",
		"Mauritius",
		"Mexico",
		"Moldova",
		"Monaco",
		"Mongolia",
		"Montenegro",
		"Morocco",
		"Mozambique",
		"Myanmar",
		"Namibia",
		"Nauru",
		"Nepal",
		"Netherlands",
		"Nicaragua",
		"Niger",
		"Nigeria",
		"Norway",
		"Oman",
		"Qatar",
		"Pakistan",
		"Palau",
		"Panama",
		"Paraguay",
		"Peru",
		"Philippines",
		"Poland",
		"Portugal",
		"Romania",
		"Russia",
		"Rwanda",
		"Samoa",
		"Senegal",
		"Serbia",
		"Seychelles",
		"Singapore",
		"Slovenia",
		"Somalia",
		"Spain",
		"Grenadines",
		"SudanR",
		"Suriname",
		"Swaziland",
		"Sweden",
		"Switzerland",
		"Tajikistan",
		"Tanzania",
		"Thailand",
		"Togo",
		"Tonga",
		"Tunisia",
		"Turkey",
		"Turkmenistan",
		"Tuvalu",
		"Uganda",
		"Ukraine",
		"UK",
		"US",
		"Uruguay",
		"Uzbekistan",
		"Vanuatu",
		"Venezuela",
		"Vietnam",
		"Yemen",
		"Zambia",
		"Zimbabwe",
	};
	std::cout << random(0, 163);
	return words[random(0, 163)];
}

int letterFill(char guess, string secretword, string &guessword){
    int matches=0;
    int len = secretword.length();

    for (int i = 0; i < len; i++)
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
	int tries = 6;
	string letter = "";
	string word = randomWord();
	string unknown(word.length(), '_');
	cout << "Welcome to hangman mang!" << endl;
	cout << "Random word has been generated! Word is " << word.length() << " letters long!" << endl;
	while (tries > 0){
		cout << unknown << endl;
        char letter = cin.get();
		if (letterFill(letter, word, unknown) == 0){
			cout << "Could not find " << letter << " in the word." << endl;
			tries--;
		}
		else {
			cout << "Found letter! " << endl;
		}

		cout << "Guess a letter, you have " << tries << " left." << endl;

		if (word == unknown)
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
            return 0;
		}
	}
	cout << endl << "Sorry, you lose...you've been hanged." << endl;
	cout << "The word was : " << word << endl;
	//cin.ignore();

	return 0;
}
