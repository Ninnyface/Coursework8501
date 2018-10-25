#include "IO.h"

using namespace std;

//Method to write all information needed in the key file
void IO::writeKeyFile(Safe* s) {

	keyFile.open(keyFileName, std::ofstream::out | std::ofstream::app);
	if (keyFile.is_open()) {
		s->printSafeKey(&keyFile);
		keyFile.close();
	}
	else {
		cout << "Unable to access file: " << keyFileName << "\n";
	}
}

//Method to read in the key file and add all of the data stored inside to a vector of safes
vector<Safe*> IO::readKeyFile() {
	vector<Safe*> safes;
	string line;
	keyFileIn.open(keyFileName, std::ofstream::in);
	if (keyFileIn.is_open()) {
		while (getline(keyFileIn, line)) {
			//As the structure of the key file is known, substrings can be obtained to retrieve the individual hash values
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
		cout << "Unable to access file: " << keyFileName << "\n";
	}

	return safes;
}

//Method to validate solutions and write to the multi-safe file
void IO::writeMultiSafeFile(Safe* s, int i) {
	multiSafeFile.open(multiSafeFileName, std::ofstream::out | std::ofstream::app);
	if (multiSafeFile.is_open()) {
		s->printMultiSafe(&multiSafeFile, i);
		multiSafeFile.close();
	}
	else {
		cout << "Unable to access file: " << multiSafeFileName << "\n";
	}
}