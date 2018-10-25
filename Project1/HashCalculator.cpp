#include "HashCalculator.h"

vector<Vector4> HashCalculator::calculateHashes(vector<Vector4> safe) {
	vector<Vector4> values;
	vector<int> xValues;
	vector<int> yValues;
	vector<int> zValues;
	vector<int> wValues;

	for (int i = 0; i < safe.size(); i++) {
		xValues.push_back(safe.at(i).x);
		yValues.push_back(safe.at(i).y);
		zValues.push_back(safe.at(i).z);
		wValues.push_back(safe.at(i).w);
	}

	calculateUHFAndLHF(xValues, yValues, zValues, wValues);

	//PHF = Vector4(calculatePHF(xValues), calculatePHF(yValues), calculatePHF(zValues), calculatePHF(wValues));

	calculatePHF(xValues.at(1), yValues.at(1), zValues.at(1), wValues.at(1));

	values.push_back(finalUHF);
	values.push_back(finalLHF);
	values.push_back(finalPHF);

	return values;
}

void HashCalculator::calculateUHFAndLHF(vector<int> x, vector<int> y, vector<int> z, vector<int> w) {
	int differenceX = x.at(1) - x.at(0);
	int differenceCountX = 0;
	if (differenceX <= 1 || differenceX >= -1) {
		differenceCountX = 1;
	}
	if (differenceX <= 1) {
		differenceX -= 10;
	}
	else {
		differenceX -= 20;
	}

	int differenceY = y.at(1) - y.at(0);
	int differenceCountY = 0;
	if (differenceY <= 1 || differenceY >= -1) {
		differenceCountY = 1;
	}
	if (differenceY <= 1) {
		differenceY -= 10;
	}
	else {
		differenceY -= 20;
	}

	int differenceZ = z.at(1) - z.at(0);
	int differenceCountZ = 0;
	if (differenceZ <= 1 || differenceZ >= -1) {
		differenceCountZ = 1;
	}
	if (differenceZ <= 1) {
		differenceZ -= 10;
	}
	else {
		differenceZ -= 20;
	}

	int differenceW = w.at(1) - w.at(0);
	int differenceCountW = 0;
	if (differenceW <= 1 || differenceW >= -1) {
		differenceCountW = 1;
	}
	if (differenceW <= 1) {
		differenceW -= 10;
	}
	else {
		differenceW -= 20;
	}

	int UHFx, UHFy, UHFz, UHFw;
	int LHFx, LHFy, LHFz, LHFw;
	bool validValues = false;
	while (!validValues) {

		while (differenceCountX < 3) {
			
				if (differenceX > 0) {
					UHFx = 9;
					LHFx = differenceX - UHFx;
				}
				else {
					LHFx = -9;
					UHFx = differenceX - UHFx;	
			}
			while (LHFx < 9 && UHFx > -9) {

				while (differenceCountY < 3) {
				
						if (differenceY > 0) {
							UHFy = 9;
							LHFy = differenceY - UHFy;						
						}
						else {
							LHFy = -9;
							UHFy = differenceY - UHFy;					
					}

					while (LHFy < 9 && UHFy > -9) {
						while (differenceCountZ < 3) {
							
								if (differenceZ > 0) {
									UHFz = 9;
									LHFz = differenceZ - UHFz;
								}
								else {
									LHFz = -9;
									UHFz = differenceZ - UHFz;
								}
						
								while (LHFz < 9 && UHFz > -9) {

									while (differenceCountW < 3) {

										if (differenceW > 0) {
											UHFw = 9;
											LHFw = differenceW - UHFw;
										}
										else {
											LHFw = -9;
											UHFw = differenceW - UHFw;
										}

										while (LHFw < 9 && UHFw > -9) {
											if (validCombination(Vector4(UHFx, UHFy, UHFz, UHFz),Vector4(LHFx, LHFy, LHFz, LHFz), Vector4(x.at(2), y.at(2), z.at(2), w.at(3)))) {
												finalUHF = Vector4(UHFx, UHFy, UHFz, UHFw);
												finalLHF = Vector4(LHFx, LHFy, LHFz, LHFw);
												validValues = true;
											}
											LHFw++;
											UHFw--;
										}
										differenceCountW++;
										differenceW += 10;
									}
									LHFz++;
									UHFz--;
								}
							differenceCountZ++;
							differenceZ += 10;
						}
						LHFy++;
						UHFy--;
					}	
					differenceCountY++;
					differenceY += 10;
				}
				LHFx++;
				UHFx--;
			}	
			differenceCountX++;
			differenceX += 10;
		}
		if (differenceCountX == 4) {
			break;
		}
	}
}

void HashCalculator::calculatePHF(int x, int y, int z, int w) {
	HN0 = Vector4(CN1.x - finalUHF.x, CN1.y - finalUHF.y, CN1.z - finalUHF.z, CN1.w - finalUHF.w);
	finalPHF = Vector4(HN0.x - x, HN0.y - y, HN0.z - z, HN0.w - w);
}

bool HashCalculator::validCombination(Vector4 a, Vector4 b, Vector4 LN) {
	CN1 = Vector4(LN.x - b.x, LN.y - b.y, LN.z - b.z, LN.w - b.w);
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 4; j++) {
			if (CN1.at(i) == CN1.at(j)) {
				return false;
			}
		}
	}	
}