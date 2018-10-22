#include "Safe.h"

void Safe::setRoot() {
	int x;
	cout << "Please enter the 4 digit root value: " << "\n";
	cin >> x;

	//Integer magic
	root = Vector4(x / 1000,
		(x - ((x / 1000) * 1000)) / 100,
		(x - ((x / 1000) * 1000) - ((x - ((x / 1000) * 1000)) / 100) * 100) / 10,
		(x - ((x / 1000) * 1000) - ((x - ((x / 1000) * 1000)) / 100) * 100) - ((x - ((x / 1000) * 1000) - ((x - ((x / 1000) * 1000)) / 100) * 100) / 10) * 10);

}

void Safe::setUHF() {
	int x;
	cout << "Please enter the 4 digits of the unlock hash function (UHF) individually: " << "\n";
	cin >> x;
	UHF.x = x;
	cin >> x;
	UHF.y = x;
	cin >> x;
	UHF.z = x;
	cin >> x;
	UHF.w = x;
}

void Safe::setLHF() {
	int x;
	cout << "Please enter the 4 digits of the lock hash function (LHF) individually: " << "\n";
	cin >> x;
	LHF.x = x;
	cin >> x;
	LHF.y = x;
	cin >> x;
	LHF.z = x;
	cin >> x;
	LHF.w = x;
}

void Safe::setPHF() {
	int x;
	cout << "Please enter the 4 digits of the pass hash function (PHF) individually: " << "\n";
	cin >> x;
	LHF.x = x;
	cin >> x;
	LHF.y = x;
	cin >> x;
	LHF.z = x;
	cin >> x;
	LHF.w = x;
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