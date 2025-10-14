
/*
Name: Yoni Kalev
CWID: 832710651
Email: kalevyoni2006@csu.fullerton.edu
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string encrypt(string plaintext, int key);
string decrypt(string ciphertext, int key);
void encryptFile(string inputFileName, string outputFileName, int key);
void decryptFile(string inputFileName, string outputFileName, int key);

int main() {
    int choice;
    string inputFile;
    string outputFile;
    int key;

    std::cout << "========================================" << endl;
    std::cout << "  File Encyption/Decryption Program" << endl;
    std::cout << "  Technique: Substitution Cipher" << endl;
    std::cout << "========================================" << endl;
    std::cout << "1. Encrypt a file" << endl;
    std::cout << "2. Decrypt a file" << endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    std::cout << "Enter the input file name: ";
    std::cin >> inputFile;
    std::cout << "Enter the output file name: ";
    std::cin >> outputFile;
    std::cout << "Enter the encyption/decryption key (integer): ";
    std::cin >> key;

    if (choice == 1) {
        encryptFile(inputFile, outputFile, key);
        std::cout << "File encrypted successfully!" << endl;
    } 
    else if (choice == 2) {
        decryptFile(inputFile, outputFile, key);
        std:;cout << "File decrypted successfully!" << endl;
    }
    else {
        std::cout << "Invalid choice." << endl;
    }
    return 0;
}

