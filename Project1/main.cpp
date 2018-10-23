#include <iostream>
#include <string>
#include <ctime>
#include "IO.h"
#include "Vector4.h"
#include "Safe.h"

using namespace std;

int main() {
	
	srand(time(NULL));
	//int safesCreated = 0;
	int validSolutions = 0;
	IO* iO = new IO();
	
	int solutions;
	cout << "How many solutions would you like?" << "\n";
	cin >> solutions;

	while (validSolutions < solutions) {
		Safe* s = new Safe();
		s->setRoot();
		s->setUHF();
		s->setLHF();
		s->setPHF();
		s->createLocks();	
		iO->writeKeyFile(s);
		if (s->validSafe()) {
			validSolutions++;
		}
		
		//safesCreated++;
		s->deleteLocks();
		delete s;
		s = NULL;
	}
	
	cout << "Key file created." << "\n";
	
	vector<Safe*> safes;
	safes = iO->readKeyFile();
	for (int i = 0; i < safes.size(); i++) {
		iO->writeMultiSafeFile(safes.at(i), i);
		safes.at(i)->deleteLocks();
		delete safes.at(i);
		safes.at(i) = NULL;
	}

	safes.clear();

	delete iO;
	iO = NULL;
	int x;
	cin >> x;


	return 0;
}