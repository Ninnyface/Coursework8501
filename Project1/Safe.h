#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "Vector4.h"
#include "Lock.h"

using namespace std;

class Safe {
public:
	Safe(void) {
		root = Vector4(0, 0, 0, 0);
		UHF = Vector4(0, 0, 0, 0);
		LHF = Vector4(0, 0, 0, 0);
		PHF = Vector4(0, 0, 0, 0);
		
	};

	~Safe(void) {};

	void setRoot();
	void setUHF();
	void setLHF();
	void setPHF();
	void createLocks();
	void deleteLocks();
	void printSafe();
	void printSafeKey(ofstream* file);
	void printMultiSafe(ofstream* file, int safeNumber);
	bool validSafe();

private:
	int nOfLocks;
	Vector4 root;
	Vector4 UHF;
	Vector4 LHF;
	Vector4 PHF;
	vector<Lock*> locks;
};