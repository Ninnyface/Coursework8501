#include "Safe.h"

void Safe::setRoot() {
	
	/* RANDOM GENERATION */
	root = Vector4(rand() % 10, rand() % 10, rand() % 10, rand() % 10);
	cout << "Root number is: " << root.x << root.y << root.z << root.w << "\n";
	
	/* MANUAL GENERATION */
	/*int x;
	cout << "Please enter the 4 digit root value: " << "\n";
	cin >> x;

	//Integer magic
	root = Vector4(x / 1000,
		(x - ((x / 1000) * 1000)) / 100,
		(x - ((x / 1000) * 1000) - ((x - ((x / 1000) * 1000)) / 100) * 100) / 10,
		(x - ((x / 1000) * 1000) - ((x - ((x / 1000) * 1000)) / 100) * 100) - ((x - ((x / 1000) * 1000) - ((x - ((x / 1000) * 1000)) / 100) * 100) / 10) * 10);*/

}

void Safe::setUHF() {

	/* RANDOM GENERATION */
	UHF = Vector4(rand() % 19 - 9, rand() % 19 - 9, rand() % 19 - 9, rand() % 19 - 9);
	cout << "UHF is: " << UHF.x << UHF.y << UHF.z << UHF.w << "\n";

	/* MANUAL GENERATION */
	/*int x;
	cout << "Please enter the 4 digits of the unlock hash function (UHF) individually: " << "\n";
	cin >> x;
	UHF.x = x;
	cin >> x;
	UHF.y = x;
	cin >> x;
	UHF.z = x;
	cin >> x;
	UHF.w = x;*/
}

void Safe::setLHF() {

	/* RANDOM GENERATION */
	LHF = Vector4(rand() % 19 - 9, rand() % 19 - 9, rand() % 19 - 9, rand() % 19 - 9);
	cout << "LHF is: " << LHF.x << LHF.y << LHF.z << LHF.w << "\n";
	
	/* MANUAL GENERATION */
	/*int x;
	cout << "Please enter the 4 digits of the lock hash function (LHF) individually: " << "\n";
	cin >> x;
	LHF.x = x;
	cin >> x;
	LHF.y = x;
	cin >> x;
	LHF.z = x;
	cin >> x;
	LHF.w = x;*/
}

void Safe::setPHF() {

	/* RANDOM GENERATION */
	PHF = Vector4(rand() % 19 - 9, rand() % 19 - 9, rand() % 19 - 9, rand() % 19 - 9);
	cout << "PHF is: " << PHF.x << PHF.y << PHF.z << PHF.w << "\n";
	
	/* MANUAL GENERATION */
	/*int x;
	cout << "Please enter the 4 digits of the pass hash function (PHF) individually: " << "\n";
	cin >> x;
	PHF.x = x;
	cin >> x;
	PHF.y = x;
	cin >> x;
	PHF.z = x;
	cin >> x;
	PHF.w = x;*/
}

void Safe::createLocks() {
	//int nOfLocks;
	//cout << "How many locks are present in the system?" << "\n";
	//cin >> nOfLocks;
	nOfLocks = 5;

	for (int i = 0; i < nOfLocks; i++) {
		if (locks.empty()) {
			locks.push_back(new Lock(root, UHF, LHF, PHF));
		}
		else {
			locks.push_back(new Lock(locks.at(i-1)->getHashNumber(), UHF, LHF, PHF));
		}
	}
}

void Safe::deleteLocks() {
	for (int i = 0; i < nOfLocks; i++) {
		delete locks.at(i);
	}
	locks.clear();
}

void Safe::printSafe() {
	for (int i = 0; i < nOfLocks; i++) {
		cout << "CN" << i << " " << locks.at(i)->getCombinationNumber().x << locks.at(i)->getCombinationNumber().y << locks.at(i)->getCombinationNumber().z << locks.at(i)->getCombinationNumber().w;
		cout << ", LN" << i << " " << locks.at(i)->getLockNumber().x << locks.at(i)->getLockNumber().y << locks.at(i)->getLockNumber().z << locks.at(i)->getLockNumber().w;
		cout << ", HN" << i << " " << locks.at(i)->getHashNumber().x << locks.at(i)->getHashNumber().y << locks.at(i)->getHashNumber().z << locks.at(i)->getHashNumber().w << "\n";
	}
}