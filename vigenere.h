#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>
#include <vector>

using namespace std;

class Vigenere
{
public:
	Vigenere(const string & k = "lemon");

	//accessor(s)
	string getKey();

	//mutator(s)
	void setKey(string & newKey);

	//Encoding and decoding member functions
	string encode(string & message);
	string decode(string & message);

	//shift letter
	char shift(char c, int k);

private:
	string key;
	vector<int> shifts;
	vector<int> decodeShifts;
	//internal function (private)
	string cipher(string & message, vector<int> shifts);
};
#endif
