#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Safe.h"

using namespace std;

class IO {
public:

	IO(int lockedSafes) {
		keyFile.open(keyFileName);
		keyFile.close();
		lockedFile.open(lockedFileName);
		lockedFile << "NL " << lockedSafes << "\n";
		lockedFile.close();
		multiSafeFile.open(multiSafeFileName);
		multiSafeFile.close();
	};

	~IO(void) {};

	void writeKeyFile(Safe* s);
	vector<Safe*> readKeyFile();
	void writeMultiSafeFile(Safe* s, int i);
	void writeLockedSafeFile(Safe* s);
	vector<vector<Vector4>> readLockedFile();


private:
	ofstream lockedFile;
	string lockedFileName = "lockfile.txt";
	ofstream keyFile;
	string keyFileName = "keyfile.txt";
	ofstream multiSafeFile;
	string multiSafeFileName = "multisafefile.txt";
	ifstream keyFileIn;
	ifstream lockedFileIn
};