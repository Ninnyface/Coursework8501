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
	void setRoot(int x, int y, int z, int w);
	void setUHF();
	void setUHF(int x, int y, int z, int w);
	void setLHF();
	void setLHF(int x, int y, int z, int w);
	void setPHF();
	void setPHF(int x, int y, int z, int w);
	void setMultiSafe(bool multiSafe) { this->multiSafe = multiSafe; };
	void createLocks();
	void deleteLocks();
	void printSafe();
	void printSafeKey(ofstream* file);
	void printLockKey(ofstream* file);
	void printMultiSafe(ofstream* file, int safeNumber);
	bool validSafe();

private:
	int nOfLocks;
	bool multiSafe;
	Vector4 root;
	Vector4 UHF;
	Vector4 LHF;
	Vector4 PHF;
	vector<Lock*> locks;
};