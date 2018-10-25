#pragma once
#include "Safe.h"

class HashCalculator {
public:
	HashCalculator() {};
	
	vector<Vector4> calculateHashes(vector<Vector4>);
	void calculateUHFAndLHF(vector<int>, vector<int>, vector<int>, vector<int>);
	void calculatePHF(int, int ,int, int);
	bool validCombination(Vector4, Vector4, Vector4);

private:
	Vector4 HN0;
	Vector4 CN1;
	Vector4 finalUHF;
	Vector4 finalLHF;
	Vector4 finalPHF;
};