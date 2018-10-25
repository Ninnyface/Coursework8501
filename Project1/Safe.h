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

	Vector4 getUHF() { return UHF; }
	Vector4 getLHF() { return LHF; }
	Vector4 getPHF() { return PHF; }

	void setRoot();
	void setRoot(Vector4);
	void setUHF();
	void setUHF(Vector4);
	void setLHF();
	void setLHF(Vector4);
	void setPHF();
	void setPHF(Vector4);
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