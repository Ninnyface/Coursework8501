#include <iostream>
#include <string>
#include "Vector4.h"

using namespace std;

int main() {
	
	int x;
	cout << "Please enter the 4 digit root value: " << "\n";
	cin >> x;
	
	//Integer magic
	Vector4 root = Vector4(x / 1000, 
						(x - ((x / 1000) * 1000)) / 100, 
						(x - ((x / 1000) * 1000) - ((x - ((x / 1000) * 1000)) / 100) * 100) / 10, 
						(x - ((x / 1000) * 1000) - ((x - ((x / 1000) * 1000)) / 100) * 100) - ((x - ((x / 1000) * 1000) - ((x - ((x / 1000) * 1000)) / 100) * 100) / 10) * 10);
	cout << root.x << " " << root.y << " " << root.z << " " <<  root.w <<"\n";
	
	Vector4 UHF;
	cout << "Please enter the 4 digits of the unlock hash function (UHF) individually: " << "\n";
	cin >> x;
	UHF.x = x;
	cin >> x;
	UHF.y = x;
	cin >> x;
	UHF.z = x;
	cin >> x;
	UHF.w = x;

	cout << UHF.x << " " << UHF.y << " " << UHF.z << " " << UHF.w << "\n";

	Vector4 LHF;
	cout << "Please enter the 4 digits of the lock hash function (LHF) individually: " << "\n";
	cin >> x;
	LHF.x = x;
	cin >> x;
	LHF.y = x;
	cin >> x;
	LHF.z = x;
	cin >> x;
	LHF.w = x;

	cout << LHF.x << " " << LHF.y << " " << LHF.z << " " << LHF.w << "\n";

	Vector4 PHF;
	cout << "Please enter the 4 digits of the pass hash function (PHF) individually: " << "\n";
	cin >> x;
	LHF.x = x;
	cin >> x;
	LHF.y = x;
	cin >> x;
	LHF.z = x;
	cin >> x;
	LHF.w = x;

	cout << LHF.x << " " << LHF.y << " " << LHF.z << " " << LHF.w << "\n";

	cin >> x;
}