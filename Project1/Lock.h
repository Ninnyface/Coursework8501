#pragma once

class Lock {
public:
	Lock(void) {};

	~Lock(void) {};

	Lock(Vector4 root, Vector4 UHF, Vector4 LHF, Vector4 PHF) {
		combinationNumber = Vector4(root.x + UHF.x, root.y + UHF.y, root.z + UHF.z, root.w + UHF.w);
		lockNumber = Vector4(root.x + LHF.x, root.y + LHF.y, root.z + LHF.z, root.w + LHF.w);
		hashNumber = Vector4(root.x + PHF.x, root.y + PHF.y, root.z + PHF.z, root.w + PHF.w);
	};
	
	Vector4 getHashNumber() { return hashNumber; }

private:
	Vector4 combinationNumber;
	Vector4 lockNumber;
	Vector4 hashNumber;
};