#include <iostream>
#include <string>

std::string XORCipher(const std::string& inputString, const std::string& key) {
    int keySize = key.size();
    int inputSize = inputString.size();
    std::string xorString = inputString;
    for (int i = 0; i < inputSize; i++) {
        xorString[i] = char(int(inputString[i]) ^ int(key[i%keySize]));
    }

    return xorString;
}

std::string encryptXOR(const std::string& inputString, const std::string& key) {
    return XORCipher(inputString, key);
}

std::string decryptXOR(const std::string& inputString, const std::string& key) {
    return XORCipher(inputString, key);
}

int main() {
    std::string key, inputString, encryptedString;

    std::cout << "Enter input: ";
    std::getline(std::cin, inputString);
    std::cout << "Enter key: ";
    std::getline(std::cin, key);

    encryptedString = encryptXOR(inputString, key);
    std::cout << encryptedString << std::endl; //Encryption using key 
    std::cout << decryptXOR(encryptedString, key) << std::endl; //Decryption using same key and function
    return 0;
}
