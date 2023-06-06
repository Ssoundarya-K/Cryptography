#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string affine_encrypt(const string& plain_text, int a, int b) {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string encrypted_text = "";
    
    for (char c : plain_text) {
        if (isalpha(c)) {
            char upper_c = toupper(c);
            int index = alphabet.find(upper_c);
            int encrypted_index = (a * index + b) % 26;
            char encrypted_char = alphabet[encrypted_index];
            encrypted_text += encrypted_char;
        } else {
            encrypted_text += c;
        }
    }
    
    return encrypted_text;
}

string affine_decrypt(const string& cipher_text, int a, int b) {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string decrypted_text = "";
    int a_inverse = 0;
    
    for (int i = 0; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            a_inverse = i;
            break;
        }
    }
    
    for (char c : cipher_text) {
        if (isalpha(c)) {
            char upper_c = toupper(c);
            int index = alphabet.find(upper_c);
            int decrypted_index = (a_inverse * (index - b + 26)) % 26;
            char decrypted_char = alphabet[decrypted_index];
            decrypted_text += decrypted_char;
        } else {
            decrypted_text += c;
        }
    }
    
    return decrypted_text;
}

int main() {
    string plain_text;
    int a, b;
    
    cout << "Enter the plain text: ";
    getline(cin, plain_text);
    
    cout << "Enter the multiplicative value: ";
    cin >> a;
    
    cout << "Enter the additive value: ";
    cin >> b;
    
    string encrypted_text = affine_encrypt(plain_text, a, b);
    cout << "Encrypted text: " << encrypted_text << endl;
    
    string decrypted_text = affine_decrypt(encrypted_text, a, b);
    cout << "Decrypted text: " << decrypted_text << endl;
    
    return 0;
}
