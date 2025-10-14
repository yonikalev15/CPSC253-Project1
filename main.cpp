
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
    std::cout << "  File Encryption/Decryption Program" << endl;
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
    std::cout << "Enter the encryption/decryption key (integer): ";
    std::cin >> key;

    if (choice == 1) {
        encryptFile(inputFile, outputFile, key);
        std::cout << "File encrypted successfully!" << endl;
    } 
    else if (choice == 2) {
        decryptFile(inputFile, outputFile, key);
        std::cout << "File decrypted successfully!" << endl;
    }
    else {
        std::cout << "Invalid choice." << endl;
    }
    return 0;
}


string encrypt(string plaintext, int key) {
    string result = "";
    for (int i = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];
        int shift = (key + i * 7) % 256;
        char encrypted = c + shift;
        result += encrypted;
    }
    return result;
}

string decrypt(string ciphertext, int key) {
    string result = "";
    for (int i = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];
        int shift = (key + i * 7) % 256;
        char decrypted = c - shift;
        result += decrypted;
    }
    return result;
}

void encryptFile(string inputFileName, string outputFileName, int key) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    string line;

    if (!inputFile.is_open()) {
        std::cout << "Error: Cannot open input file!" << endl;
        return;
    }

    if (!outputFile.is_open()) {
        std::cout << "Error: Cannot create output file!" << endl;
        return;
    }

    while (getline(inputFile, line)) {
        outputFile << encrypt(line, key) << endl;
    }

    inputFile.close();
    outputFile.close();
}

void decryptFile(string inputFileName, string outputFileName, int key) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    string line;

    if (!inputFile.is_open()) {
        std::cout << "Error: Cannot open input file!" << endl;
        return;
    }

    if (!outputFile.is_open()) {
        std::cout << "Error: Cannot create output file!" << endl;
        return;
    }

    while (getline(inputFile, line)) {
        outputFile << decrypt(line, key) << endl;
    }

    inputFile.close();
    outputFile.close();
}