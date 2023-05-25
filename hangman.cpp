#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
using namespace std;

string wordlist(string* _word) {
	string word_list1[14]{};
	ifstream word_list("wordlist.txt");
	if (!word_list) {
		cout << "There is a problem with the file!!" << endl;
	}
	else {
		for (int i = 0; i < 14; i++) {
			word_list >> word_list1[i];
		}
	}
	word_list.close();
	*_word = word_list1[rand() % 14];
	return *_word;
}

void savegame(string _word, char* _wrong_letters, int _number_of_letters_entered, int _guess_count) {
	ofstream save_file("savegame.txt");
	if (!save_file) {
		cout << "There is a problem with the file!!" << endl;
	}
	else {
		save_file << _word << endl;
		save_file << _number_of_letters_entered << endl;
		for (int i = 0; i < _number_of_letters_entered; i++) {
			save_file << _wrong_letters[i] << " ";
		}
		save_file << endl;
		save_file << _guess_count << endl;
	}
	save_file.close();
	cout << "Game saved successfully!" << endl;
}

void loadgame(string* _word, char* _wrong_letters, int* _number_of_letters_entered, int* _guess_count) {
	ifstream load_file("savegame.txt");
	if (!load_file) {
		cout << "There is no saved game!" << endl;
	}
	else {
		getline(load_file, *_word);
		load_file >> *_number_of_letters_entered;
		for (int i = 0; i < *_number_of_letters_entered; i++) {
			load_file >> _wrong_letters[i];
		}
		load_file >> *_guess_count;
	}
	load_file.close();
}

int mainmenu(char* _choice) {
	cout << "*********** WELCOME TO HANGMAN GAME ***********" << endl << endl;
	cout << "1 - NEW GAME" << endl << endl;
	cout << "2 - LOAD GAME" << endl << endl;
	cout << "3 - QUIT" << endl << endl;
	*_choice = _getch();
	system("cls");
	return *_choice;
}

void drawhangman(int _guess_count) {
	if (_guess_count >= 9) {
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
		cout << char(186) << " " << " " << " " << " " << " " << " " << char(186) << endl;
		cout << char(186) << " " << " " << " " << " " << " " << " " << char(79) << endl;
		cout << char(186) << " " << " " << " " << " " << " " << char(47) << char(179) << char(92) << endl;
		cout << char(186) << " " << " " << " " << " " << " " << char(47) << " " << char(92) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl << endl;
	}
	else if (_guess_count >= 8) {
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
		cout << char(186) << " " << " " << " " << " " << " " << " " << char(186) << endl;
		cout << char(186) << " " << " " << " " << " " << " " << " " << char(79) << endl;
		cout << char(186) << " " << " " << " " << " " << " " << char(47) << char(179) << char(92) << endl;
		cout << char(186) << " " << " " << " " << " " << " " << char(47) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl << endl;
	}
	else if (_guess_count >= 7) {
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
		cout << char(186) << " " << " " << " " << " " << " " << " " << char(186) << endl;
		cout << char(186) << " " << " " << " " << " " << " " << " " << char(79) << endl;
		cout << char(186) << " " << " " << " " << " " << " " << char(47) << char(179) << char(92) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl << endl;
	}
	else if (_guess_count >= 6) {
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
		cout << char(186) << " " << " " << " " << " " << " " << " " << char(186) << endl;
		cout << char(186) << " " << " " << " " << " " << " " << " " << char(79) << endl;
		cout << char(186) << " " << " " << " " << " " << " " << char(47) << char(179) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl << endl;
	}
	else if (_guess_count >= 5) {
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
		cout << char(186) << " " << " " << " " << " " << " " << " " << char(186) << endl;
		cout << char(186) << " " << " " << " " << " " << " " << " " << char(79) << endl;
		cout << char(186) << " " << " " << " " << " " << " " << " " << char(179) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl << endl;
	}
	else if (_guess_count >= 4) {
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
		cout << char(186) << " " << " " << " " << " " << " " << " " << char(186) << endl;
		cout << char(186) << " " << " " << " " << " " << " " << " " << char(79) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl << endl;
	}
	else if (_guess_count >= 3) {
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
		cout << char(186) << " " << " " << " " << " " << " " << " " << char(186) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl << endl;
	}
	else if (_guess_count >= 2) {
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl << endl;
	}
	else if (_guess_count >= 1) {
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl << endl;
	}
}

void gamewin(int _guess_count, string _word, char* _wrong_letters, int _number_of_letters_entered) {
	cout << "------- Congratulations! You have known the word -------" << endl << endl;
	drawhangman(_guess_count);
	cout << "WORD = " << _word << endl << endl;
	cout << "Incorrectly guessed letters = ";
	for (int a = 0; a < _number_of_letters_entered; a++) {
		cout << _wrong_letters[a] << " ";
	}
	cout << endl << endl;
}
void gameover(int _guess_count, string _word, char* _wrong_letters, int _number_of_letters_entered) {
	cout << "------------- Game Over -------------" << endl << endl;
	drawhangman(_guess_count);
	cout << "WORD = " << _word << endl << endl;
	cout << "Incorrectly guessed letters = ";
	for (int a = 0; a < _number_of_letters_entered; a++) {
		cout << _wrong_letters[a] << " ";
	}
	cout << endl << endl;
	cout << "Game Over!!" << endl << endl;
}

int main()
{
	srand(time(nullptr));
	
	string word;
	wordlist(&word);
	char guess_letter;
	char* wrong_letters = new char[9];
	int number_of_letters_entered = 0;
	int word_length = word.length();
	char* letters_found = new char[word_length];
	int guess_count = 0;
	char choice;
	mainmenu(&choice);

	if (choice == '1') {
		cout << "----------------- NEW GAME -----------------" << endl << endl;
		for (int a = 0; a < word_length; a++) {
			letters_found[a] = '_';
		}
		while (guess_count < 9) {
			bool letter_check = false;
			cout << "The word = ";
			for (int b = 0; b < word_length; b++) {
				cout << letters_found[b] << "  ";
			}
			if (number_of_letters_entered != 0) {
				cout << endl << endl;
				cout << "Incorrectly guessed letters = ";
				for (int c = 0; c < number_of_letters_entered; c++) {
					cout << wrong_letters[c] << " ";
				}
			}
			cout << endl << endl;
			cout << "Guess a letter = ";
			guess_letter = _getch();
			char _guess_letter = toupper(guess_letter);
			int number_of_absent_letter = 0;
			system("cls");
			cout << "-------- Press Escape to Save and Return to Main Menu --------" << endl << endl;
			for (int d = 0; d < word_length; d++) {
				if (int(guess_letter) == 32) {
					system("cls");
					savegame(word, wrong_letters, number_of_letters_entered, guess_count);
					return main();
					exit(0);
				}
				else if (!(int(_guess_letter) >= 65 && int(_guess_letter) <= 90)) {
					cout << "This is not a letter!! Please enter a letter." << endl << endl;
					break;
				}
				else if (_guess_letter != word[d]) {
					number_of_absent_letter++;
				}
				else {
					for (int e = 0; e < word_length; e++) {
						if (!letter_check) {
							if (_guess_letter == letters_found[e]) {
								cout << "This letter has already been opened." << endl << endl;
								letter_check = true;
							}
						}
					}
					letters_found[d] = _guess_letter;
					letter_check = true;
				}
				if (d == word_length - 1) {
					if (number_of_absent_letter == word_length) {
						for (int f = 0; f <= number_of_letters_entered; f++) {
							if (f == number_of_letters_entered) {
								wrong_letters[number_of_letters_entered] = _guess_letter;
								number_of_letters_entered++;
								int smallest = abs(_guess_letter - word[0]);
								for (int g = 1; g < word_length; g++) {
									if (abs(_guess_letter - word[g]) < smallest) {
										smallest = abs(_guess_letter - word[g]);
									}
								}
								if (smallest >= 6 && smallest <= 10) {
									guess_count += 2;
								}
								else if (smallest >= 11 && smallest <= 15) {
									guess_count += 3;
								}
								else if (smallest >= 16 && smallest <= 20) {
									guess_count += 4;
								}
								else if (smallest >= 21 && smallest <= 25) {
									guess_count += 5;
								}
								else
									guess_count++;
								if (guess_count != 0 && guess_count != 9)
									cout << "Wrong letter!! Try again." << endl << endl;
								break;
							}
							else if (toupper(guess_letter) == wrong_letters[f]) {
								cout << "You entered this letter before." << endl << endl;
								break;
							}
						}
					}
				}
			}
			if (word == string(letters_found, word_length)) {
				system("cls");
				gamewin(guess_count, word, wrong_letters, number_of_letters_entered);
				break;
			}
			else if (guess_count >= 9) {
				system("cls");
				gameover(guess_count, word, wrong_letters, number_of_letters_entered);
				break;
			}
			else drawhangman(guess_count);
		}
		delete[] letters_found;
		delete[] wrong_letters;
	}
	else if (choice == '2') {
		loadgame(&word, wrong_letters, &number_of_letters_entered, &guess_count);
	}
	else if (choice == '3') {
		exit(0);
	}
	else {
		return main();
		exit(0);
	}

	return 0;
}
