#include <iostream>
#include <string>
#include <ctime>
#include "IO.h"
#include "Vector4.h"
#include "Safe.h"

using namespace std;

int main() {
	
	srand(time(NULL));
	int validSolutions = 0;
	IO* iO = new IO();
	bool multiSafe = false;
	bool validInput = false;
	bool validOnly = false;
	int solutions;
	char answer;
	cout << "How many valid solutions would you like?" << "\n";
	while (!validInput) {
		cin >> solutions;
		if (!cin.fail()) {
			
			validInput = true;
		}
		else {
			cout << "Please enter an integer value." << "\n";
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
	validInput = false;

	cout << "Would you like to only output valid solutions? (y/n)" << "\n";
	while (!validInput) {
		cin >> answer;
		if (answer == 'y') {
			validOnly = true;
			validInput = true;
		}
		else if (answer == 'n') {
			validInput = true;
		}
		else {
			cout << "Please answer either 'y' (yes) or 'n' (no)." << "\n";
		}
	}
	validInput = false;

	cout << "Would you like to use BONUS MULTI_SAFE conditions? (y/n) \nWarning: this may increase the time to create solutions dramatically." << "\n";
	while (!validInput) {
		cin >> answer;
		if (answer == 'y') {
			multiSafe = true;
			validInput = true;
		}
		else if (answer == 'n') {
			validInput = true;
		}
		else {
			cout << "Please answer either 'y' (yes) or 'n' (no)." << "\n";
		}
	}
	validInput = false;

	cout << "Creating key file..." << "\n";
	while (validSolutions < solutions) {
		Safe* s = new Safe();
		s->setRoot();
		s->setUHF();
		s->setLHF();
		s->setPHF();
		s->createLocks();
		s->setMultiSafe(multiSafe);
		if (!validOnly) {
			iO->writeKeyFile(s);
			if (s->validSafe()) {
				validSolutions++;
			}
		}
		else {
			if (s->validSafe()) {
				iO->writeKeyFile(s);
				validSolutions++;
			}
		}
		s->deleteLocks();
		delete s;
		s = NULL;
	}
	
	cout << "Key file created." << "\n";
	cout << "Creating multi-safe file..." << "\n";

	vector<Safe*> safes;
	safes = iO->readKeyFile();
	for (int i = 0; i < safes.size(); i++) {
		safes.at(i)->setMultiSafe(multiSafe);
		iO->writeMultiSafeFile(safes.at(i), i);
		safes.at(i)->deleteLocks();
		delete safes.at(i);
		safes.at(i) = NULL;
	}

	cout << "Multi-safe file created. Please enter any key to finish." << "\n";
	safes.clear();

	delete iO;
	iO = NULL;
	int x;
	cin >> x;


	return 0;
}