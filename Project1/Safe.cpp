#include "Safe.h"

/*   Random or manual generation of all values   */
void Safe::setRoot() {
	root = Vector4(rand() % 10, rand() % 10, rand() % 10, rand() % 10);
}

void Safe::setRoot(int x, int y, int z, int w) {
	root = Vector4(x, y, z, w);
}

void Safe::setUHF() {
	UHF = Vector4(rand() % 19 - 9, rand() % 19 - 9, rand() % 19 - 9, rand() % 19 - 9);
}

void Safe::setUHF(int x, int y, int z, int w) {
	UHF = Vector4(x, y, z, w);
}

void Safe::setLHF() {
	LHF = Vector4(rand() % 19 - 9, rand() % 19 - 9, rand() % 19 - 9, rand() % 19 - 9);
}

void Safe::setLHF(int x, int y, int z, int w) {
	LHF = Vector4(x, y, z, w);
}

void Safe::setPHF() {
	PHF = Vector4(rand() % 19 - 9, rand() % 19 - 9, rand() % 19 - 9, rand() % 19 - 9);
}

void Safe::setPHF(int x, int y, int z, int w) {
	PHF = Vector4(x, y, z, w);
}
/*************************************************/

//Locks for each safe are created
void Safe::createLocks() {
	
	//This variable should be changed to change the number of locks per safe
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

//Deletes locks from the safe to free memory
void Safe::deleteLocks() {
	for (int i = 0; i < nOfLocks; i++) {
		delete locks.at(i);
	}
	locks.clear();
}


//Prints the safe for testing
void Safe::printSafe() {
	cout << "ROOT " << root.x << root.y << root.z << root.w << "\n";
	cout << "UHF " << UHF.x << "," << UHF.y << "," << UHF.z << "," << UHF.w << "\n";
	cout << "LHF " << LHF.x << "," << LHF.y << "," << LHF.z << "," << LHF.w << "\n";
	cout << "PHF " << PHF.x << "," << PHF.y << "," << PHF.z << "," << PHF.w << "\n";
}

//Outputs info to the key file
void Safe::printSafeKey(ofstream* file) {
	*file << "ROOT " << root.x << root.y << root.z << root.w << "\n";
	*file << "UHF " << UHF.x << "," << UHF.y << "," << UHF.z << "," << UHF.w << "\n";
	*file << "LHF " << LHF.x << "," << LHF.y << "," << LHF.z << "," << LHF.w << "\n";
	*file << "PHF " << PHF.x << "," << PHF.y << "," << PHF.z << "," << PHF.w << "\n";
}

//Outputs info to the multi safe file
void Safe::printMultiSafe(ofstream* file, int safeNumber) {
	if (this->validSafe(multiSafe)) {
		*file << "NS" << safeNumber << " VALID" << "\n";
	}
	else {
		*file << "NS" << safeNumber << " NOT VALID" << "\n";
	}
	for (int i = 0; i < nOfLocks; i++) {
		*file << "CN" << i << " " << locks.at(i)->getCombinationNumber().x << locks.at(i)->getCombinationNumber().y << locks.at(i)->getCombinationNumber().z << locks.at(i)->getCombinationNumber().w;
		*file << ", LN" << i << " " << locks.at(i)->getLockNumber().x << locks.at(i)->getLockNumber().y << locks.at(i)->getLockNumber().z << locks.at(i)->getLockNumber().w;
		*file << ", HN" << i << " " << locks.at(i)->getHashNumber().x << locks.at(i)->getHashNumber().y << locks.at(i)->getHashNumber().z << locks.at(i)->getHashNumber().w << "\n";
	}
}

//Checks whether or not the safe is a valid solution under certain conditions
bool Safe::validSafe(bool multiSafe) {
	this->multiSafe = multiSafe;
	if (!multiSafe) {	
		for (int i = 0; i < nOfLocks; i++) {
			if (locks.at(i)->repeatingNumbers()) {
				return false;
			}		
		}
		return true;
	}

	else {
		int sum = 0;
		for (int i = 0; i < nOfLocks; i++) {
			if (locks.at(i)->repeatingNumbers()) {
				return false;
			}
			sum += locks.at(i)->sumCombination();

			if (i > 0) {
				if (locks.at(i)->sumCombination() <= locks.at(i - 1)->sumCombination()) {
					//cout << "sum is lower on the right" << "\n";
					//for (int j = 0; j < nOfLocks; j++) {
					//	cout << "CN" << j << " " << locks.at(j)->getCombinationNumber().x << locks.at(j)->getCombinationNumber().y << locks.at(j)->getCombinationNumber().z << locks.at(j)->getCombinationNumber().w << "\n";
					//}
					return false;
				}
			}
		}

		if (sum % 2 != 0) {
			//cout << "odd" << "\n";
			//for (int i = 0; i < nOfLocks; i++) {
			//	cout << "CN" << i << " " << locks.at(i)->getCombinationNumber().x << locks.at(i)->getCombinationNumber().y << locks.at(i)->getCombinationNumber().z << locks.at(i)->getCombinationNumber().w;
			//}
			return false;
		}

		return true;
	}
}