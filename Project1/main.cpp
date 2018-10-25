#include <iostream>
#include <string>
#include <ctime>
#include "IO.h"
#include "Vector4.h"
#include "Safe.h"
#include "HashCalculator.h"

using namespace std;

int main() {
	
	srand(time(NULL));
	int validSolutions = 0;
	bool multiSafe = false;
	bool validInput = false;
	//bool validOnly = false;
	int solutions;
	char answer;

	cout << "How many locked safes would you like?" << "\n";
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
	IO* iO = new IO(solutions);
	/*cout << "Would you like to only output valid solutions? (y/n)" << "\n";
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
	validInput = false;*/

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

	Vector4 UHF;
	Vector4 LHF;
	Vector4 PHF;

	while (validSolutions < 1) {
		Safe* s = new Safe();
		s->setRoot();

		s->setUHF();
		UHF = s->getUHF();
		s->setLHF();
		LHF = s->getLHF();
		s->setPHF();
		PHF = s->getPHF();
		s->createLocks();
		s->setMultiSafe(multiSafe);
		
		if (s->validSafe()) {
			iO->writeLockedSafeFile(s);
			validSolutions++;
		}
		
		s->deleteLocks();
		delete s;
		s = NULL;
	}

	cout << "Creating locked safe file..." << "\n";
	while (validSolutions < solutions) {
		Safe* s = new Safe();
		s->setRoot();
		s->setUHF(UHF);
		s->setLHF(LHF);
		s->setPHF(PHF);
		s->createLocks();
		s->setMultiSafe(multiSafe);
		
		if (s->validSafe()) {
			iO->writeLockedSafeFile(s);
			validSolutions++;
		}
		
		s->deleteLocks();
		delete s;
		s = NULL;
	}



	HashCalculator* h = new HashCalculator();
	
	vector<Vector4> hashes;
	cout << "Locked safe file created." << "\n";
	vector<vector<Vector4>> safes;
	safes = iO->readLockedFile();
	for (int i = 0; i < safes.size(); i++) {
		hashes = h->calculateHashes(safes.at(i));
		for (int j = 0; j < hashes.size(); j++) {
			cout << "UHF: " << hashes.at(j).x << hashes.at(j).y << hashes.at(j).z << hashes.at(j).w << "\n";
			cout << "LHF: " << hashes.at(j).x << hashes.at(j).y << hashes.at(j).z << hashes.at(j).w << "\n";
			cout << "PHF: " << hashes.at(j).x << hashes.at(j).y << hashes.at(j).z << hashes.at(j).w << "\n";
		}
	}

	
	//cout << "Creating multi-safe file..." << "\n";

	//vector<Safe*> safes;
	//safes = iO->readKeyFile();
	//for (int i = 0; i < safes.size(); i++) {
	//	safes.at(i)->setMultiSafe(multiSafe);
	//	iO->writeMultiSafeFile(safes.at(i), i);

	//	safes.at(i)->deleteLocks();
	//	delete safes.at(i);
	//	safes.at(i) = NULL;
	//}

	//cout << "Multi-safe file created. Please enter any key to finish." << "\n";
	//safes.clear();

	delete iO;
	iO = NULL;
	int x;
	cin >> x;


	return 0;
}