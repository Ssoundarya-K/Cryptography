#include <iostream>
#include <random>
#include <ctime>
#include <string>
using namespace std;
unsigned int custom_hash(const string& message) {
    default_random_engine engine;
    engine.seed(hash<string>{}(message)); // Seed the random number generator with the hash of the message
    uniform_int_distribution<unsigned int> distribution(0, 65535); // Generate a random 16-bit hash value

    return distribution(engine);
}
int main() {
    string message;
    unsigned int hash_value;
    cout << "Enter the message: ";
    getline(cin, message);
    hash_value = custom_hash(message);
    cout << "Original Message: " << message << endl;
    cout << "Hash value: " << hash_value << endl;
    string received_message;
    unsigned int received_hash_value;
    cout << "Enter the received message: ";
    getline(cin, received_message);

    received_hash_value = custom_hash(received_message);
    cout << "Received Message: " << received_message << endl;
    cout << "Received Hash value: " << received_hash_value << endl;
    if (received_hash_value == hash_value) {
        cout << "Integrity: The message has not been modified." << endl;
    } else {
        cout << "Integrity: The message has been modified." << endl;
    }
    return 0;
}
