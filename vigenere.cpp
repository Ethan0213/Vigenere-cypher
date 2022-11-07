#include "vigenere.h"
#include <iostream>
//needs getKey and setKey
Vigenere::Vigenere(const string & k){
    key = k;
    int N= key.length();
    
    shifts = vector<int>(N);
    decodeShifts = vector<int>(N);
    
    for (int i=0;i < N; i++){
        key[i] = tolower(key[i]);
        
        shifts[i] = key[i] - 'a';
        decodeShifts[i] = 26 - shifts[i];
    }
}

char Vigenere::shift(char c, int k){
    if (isupper(c))
        return (c - 'A' + k) % 26 + 'A';
    else
        return (c - 'a' + k) % 26 + 'a';
}

string Vigenere::cipher(string & message, vector<int>  offsets){
    int N = offsets.size();
    string result = message;
    
    for(int i =0; i<message.length(); i++){
        int k = offsets[i%N];
        
        if (isalpha(message[i]))
            result[i] = shift(message[i], k);
            
    }
    return result;
}

string Vigenere::encode(string & message){ 
    return cipher(message, shifts);
}

string Vigenere::decode(string & encrypted){
    return cipher(encrypted, decodeShifts);
}

string Vigenere::getKey(){
    return key;
}
