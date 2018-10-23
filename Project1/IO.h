#pragma once
#include <iostream>
#include <fstream>
#include "Safe.h"

using namespace std;

class IO {
public:

	IO() {
		keyFile.open(keyFileName);
		keyFile.close();
		multiSafeFile.open(multiSafeFileName);
		multiSafeFile.close();
	};

	void writeKeyFile(Safe* s) {
		
		keyFile.open(keyFileName, std::ofstream::out | std::ofstream::app);
		s->printSafeKey(&keyFile);
		keyFile.close();
	}

	vector<Safe*> readKeyFile() {
		vector<Safe*> safes;
		keyFile.open(keyFileName, std::ofstream::in);
	}

	void writeMultiSafeFile(Safe* s, int i) {
		multiSafeFile.open(multiSafeFileName, std::ofstream::out | std::ofstream::app);
		s->printMultiSafe(&multiSafeFile, i);
		multiSafeFile.close();
	}
private:
	ofstream keyFile;
	string keyFileName = "keyfile.txt";
	ofstream multiSafeFile;
	string multiSafeFileName = "multisafefile.txt";
};