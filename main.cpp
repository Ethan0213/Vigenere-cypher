#include <iostream>
#include "vigenere.h"
using namespace std;

int main()
{
    string code_word;
    cout << "Enter the seceret code" << endl;
    cin >> code_word;
    
    Vigenere myVigenere;
    string message;
    cout << "Enter the message to encode the base code is " <<  myVigenere.getKey() << endl;
    getline(cin, message);//extract: \n
    getline(cin, message);
    string encoded = myVigenere.encode(message);
    
    cout << "The encoded message is: " << endl;
    cout << encoded << endl;
    
    string decoded = myVigenere.decode(encoded);
    cout << "Lets return the code to the original" << endl;
    cout << "The decrypted messsage is: " << endl;
    
    cout << decoded << endl;

    return 0;
}
