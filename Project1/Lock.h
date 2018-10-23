#pragma once

class Lock {
public:
	Lock(void) {};

	~Lock(void) {};

	Lock(Vector4 root, Vector4 UHF, Vector4 LHF, Vector4 PHF) {
		combinationNumber = Vector4((root.x + UHF.x + 10) % 10, (root.y + UHF.y + 10) % 10, (root.z + UHF.z + 10) % 10, (root.w + UHF.w + 10) % 10);
		lockNumber = Vector4((combinationNumber.x + LHF.x + 10) % 10, (combinationNumber.y + LHF.y + 10) % 10, (combinationNumber.z + LHF.z + 10) % 10, (combinationNumber.w + LHF.w + 10) % 10);
		hashNumber = Vector4((lockNumber.x + PHF.x + 10) % 10, (lockNumber.y + PHF.y + 10) % 10, (lockNumber.z + PHF.z + 10) % 10, (lockNumber.w + PHF.w + 10) % 10);
	};
	
	bool repeatingNumbers() {
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				if (combinationNumber.at(i) == combinationNumber.at(j)) {
					return true;
				}
			}
		}
		return false;
	};

	Vector4 getCombinationNumber() { return combinationNumber; }
	Vector4 getLockNumber() { return lockNumber; }
	Vector4 getHashNumber() { return hashNumber; }

private:
	Vector4 combinationNumber;
	Vector4 lockNumber;
	Vector4 hashNumber;
};