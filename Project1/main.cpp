#include <iostream>
#include <string>
#include "Vector4.h"
#include "Safe.h"

using namespace std;

int main() {
	
	Safe* s = new Safe();
	
	s->setRoot();
	s->setUHF();
	s->setLHF();
	s->setPHF();

	int x;
	cout << "Enter a number to continue." << "\n";
	cin >> x;

	s->createLocks();
	s->printSafe();

	cin >> x;

	s->deleteLocks();
	delete s;
	s = NULL;

	return 0;
}