/*
 Name: RAMYA NAYAK
 Date: January 14, 2022
 */

#include <iostream>
#include <string>
using namespace std;

// Gets the word or phrase that the user wants to encrypt/decrypt.
void GetUserInput(string* &phrase) {
    phrase = new string;
    cout << endl << "Enter a string to encrypt or decrypt:" << endl;
    getline(cin, *phrase);
}

// Encrypts/decrypts the user input.
void EncryptDecrypt(string* phrase, unsigned long phraseLength) {
    int index = 0;
    
    while(index != phraseLength) {
        if (phrase->at(index) >= 'a' && phrase->at(index) <= 'm') {
            phrase->at(index) = phrase->at(index) + 13;
        }
        else if(phrase->at(index) >= 'n' && phrase->at(index) <= 'z') {
            phrase->at(index) = phrase->at(index) - 13;
        }
        else if(phrase->at(index) >= 'A' && phrase->at(index) <= 'M') {
            phrase->at(index) = phrase->at(index) + 13;
        }
        else if(phrase->at(index) >= 'N' && phrase->at(index) <= 'Z') {
            phrase->at(index) = phrase->at(index) - 13;
        }
        ++index;
    }
}

// Prints the encrypted/decrypted word or phrase.
void OutputResult(string* phrase) {
    cout << endl << "The encrypted/decrypted string: " << *phrase << endl;
}

// ------ MAIN ------
int main(int argc, const char * argv[]) {
    
    char repetition = 'y';
    string* phrase;
    unsigned long inputLength;
    
    while (repetition == 'y') {
        int userChoice;
        
        cout << "Choose 1 or 2:" << endl;
        cout << "1. Encrypt/Decrypt" << endl;
        cout << "2. Exit" << endl;
        
        cin >> userChoice;
        cin.ignore();
        
        if (userChoice == 1) {
            GetUserInput(phrase);
            inputLength = (*phrase).length();
            EncryptDecrypt(phrase, inputLength);
            OutputResult(phrase);
            
            cout << endl << "Would you like to repeat this activity? (y/n)" << endl;
            cin >> repetition;
            cin.ignore();
            cout << endl;
            
            repetition = tolower(repetition);
            
            delete phrase;
        }
        else if (userChoice == 2) {
            repetition = 'n';
        }
        else {
            cout << endl << "Please enter a valid option." << endl << endl;
            repetition = 'y';
        }
    }
    
    return 0;
}
