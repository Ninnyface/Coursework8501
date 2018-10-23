#include "IO.h"

using namespace std;

void IO::writeKeyFile(Safe* s) {

	keyFile.open(keyFileName, std::ofstream::out | std::ofstream::app);
	s->printSafeKey(&keyFile);
	keyFile.close();
}

vector<Safe*> IO::readKeyFile() {
	vector<Safe*> safes;
	string line;
	keyFileIn.open(keyFileName, std::ofstream::in);
	if (keyFileIn.is_open()) {
		while (getline(keyFileIn, line)) {
			Safe* s = new Safe();
			string comma = ",";
			string root = line.substr(5, 4);
			s->setRoot(stoi(root.substr(0, 1)), stoi(root.substr(1, 1)), stoi(root.substr(2, 1)), stoi(root.substr(3, 1)));
			
			int x, y, z, w;
			int pos = 0;

			getline(keyFileIn, line);
			string UHF = line.substr(4, line.length());
			pos = UHF.find(comma);
			x = stoi(UHF.substr(0, pos));
			UHF.erase(0, pos + comma.length());
			pos = UHF.find(comma);
			y = stoi(UHF.substr(0, pos));
			UHF.erase(0, pos + comma.length());
			pos = UHF.find(comma);
			z = stoi(UHF.substr(0, pos));
			UHF.erase(0, pos + comma.length());
			pos = UHF.find(comma);
			w = stoi(UHF.substr(0, pos));	
			s->setUHF(x, y, z, w);

			pos = 0;
			getline(keyFileIn, line);
			string LHF = line.substr(4, line.length());
			pos = LHF.find(comma);
			x = stoi(LHF.substr(0, pos));
			LHF.erase(0, pos + comma.length());
			pos = LHF.find(comma);
			y = stoi(LHF.substr(0, pos));
			LHF.erase(0, pos + comma.length());
			pos = LHF.find(comma);
			z = stoi(LHF.substr(0, pos));
			LHF.erase(0, pos + comma.length());
			pos = LHF.find(comma);
			w = stoi(LHF.substr(0, pos));
			s->setLHF(x, y, z, w);
			
			pos = 0;
			getline(keyFileIn, line);
			string PHF = line.substr(4, line.length());
			pos = PHF.find(comma);
			x = stoi(PHF.substr(0, pos));
			PHF.erase(0, pos + comma.length());
			pos = PHF.find(comma);
			y = stoi(PHF.substr(0, pos));
			PHF.erase(0, pos + comma.length());
			pos = PHF.find(comma);
			z = stoi(PHF.substr(0, pos));
			PHF.erase(0, pos + comma.length());
			pos = PHF.find(comma);
			w = stoi(PHF.substr(0, pos));
			s->setPHF(x, y, z, w);
			s->createLocks();

			safes.push_back(s);
		}
		keyFileIn.close();
	}
	else {
		cout << "Unable to access file." << "\n";
	}

	return safes;
}

void IO::writeMultiSafeFile(Safe* s, int i) {
	multiSafeFile.open(multiSafeFileName, std::ofstream::out | std::ofstream::app);
	s->printMultiSafe(&multiSafeFile, i);
	multiSafeFile.close();
}