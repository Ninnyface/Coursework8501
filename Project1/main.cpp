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
	
	s->createLocks();


	s->deleteLocks();
	delete s;
	s = NULL;

	return 0;
}