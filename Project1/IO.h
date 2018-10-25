#pragma once
#include <iostream>
#include <fstream>
#include <string>
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

	~IO(void) {};

	void writeKeyFile(Safe* s);
	vector<Safe*> readKeyFile();
	void writeMultiSafeFile(Safe* s, int i);

private:
	ofstream keyFile;
	string keyFileName = "keyfile.txt";
	ofstream multiSafeFile;
	string multiSafeFileName = "multisafefile.txt";
	ifstream keyFileIn;
};