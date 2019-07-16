#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>

std::map<char, int> vigenereTable;
void start();
std::string encrypt(std::string plainText, std::string key);
std::string decrypt(std::string cipherText, std::string key);


int main() {
    start();
    std::string plainText, cipherText, key;
    std::getline(std::cin, plainText);
    std::transform(plainText.begin(), plainText.end(), plainText.begin(), ::toupper);
    std::getline(std::cin, key);
    std::transform(key.begin(), key.end(), key.begin(), ::toupper);

    cipherText = decrypt(plainText, key);
    std::cout << cipherText << std::endl;
}

void start() {
    for (int i = 0; i < 26; i++) {
        vigenereTable['A' + i] = i;
    }
}

std::string encrypt(std::string plainText, std::string key) {
    int size = plainText.size();
    int keySize = key.size();
    std::string cipherText = plainText;

    for (int i = 0; i < size; i++) {
        int cipher = (vigenereTable[plainText[i]] + vigenereTable[key[i%keySize]]) % 26;
        cipherText[i] = cipher + 'A';
    }

    return cipherText;
}

std::string decrypt(std::string cipherText, std::string key) {
    int size = cipherText.size();
    int keySize = key.size();
    std::string plainText = cipherText;

    for (int i = 0; i < size; i++) {
        int plain = abs((vigenereTable[cipherText[i]] - vigenereTable[key[i%keySize]]) % 26);
        plainText[i] = plain + 'A';
    }

    return plainText;
}