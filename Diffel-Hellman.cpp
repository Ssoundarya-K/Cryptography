#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool prime_checker(int p) {
    // Checks if the number entered is a prime number or not
    if (p < 2) {
        return false;
    } else if (p == 2) {
        return true;
    } else {
        for (int i = 2; i <= sqrt(p); i++) {
            if (p % i == 0) {
                return false;
            }
        }
        return true;
    }
}

int power_mod(int base, int exponent, int modulus) {
    // Calculates base^exponent % modulus using integer arithmetic
    int result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

bool primitive_check(int g, int p, const vector<int>& L) {
    // Checks if the entered number is a primitive root or not
    for (int i = 0; i < p - 1; i++) {
        if (find(L.begin(), L.end(), power_mod(g, i, p)) != L.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> L;
    int P, G;

    while (true) {
        cout << "Enter P: ";
        cin >> P;

        if (!prime_checker(P)) {
            cout << "Number Is Not Prime, Please Enter Again!" << endl;
            continue;
        }

        break;
    }

    while (true) {
        cout << "Enter The Primitive Root Of " << P << ": ";
        cin >> G;

        if (!primitive_check(G, P, L)) {
            cout << "Number Is Not A Primitive Root Of " << P << ", Please Try Again!" << endl;
            continue;
        }

        break;
    }

    int x1, x2;

    cout << "Enter The Private Key Of User 1: ";
    cin >> x1;

    cout << "Enter The Private Key Of User 2: ";
    cin >> x2;

    while (x1 >= P || x2 >= P) {
        cout << "Private Key Of Both The Users Should Be Less Than " << P << "!" << endl;
        cout << "Enter The Private Key Of User 1: ";
        cin >> x1;

        cout << "Enter The Private Key Of User 2: ";
        cin >> x2;
    }

    int y1 = power_mod(G, x1, P);
    int y2 = power_mod(G, x2, P);

    int k1 = power_mod(y2, x1, P);
    int k2 = power_mod(y1, x2, P);

    cout << "\nSecret Key For User 1 Is " << k1 << endl;
    cout << "Secret Key For User 2 Is " << k2 << endl;

    if (k1 == k2) {
        cout << "Keys Have Been Exchanged Successfully" << endl;
    } else {
        cout << "Keys Have Not Been Exchanged Successfully" << endl;
    }

    return 0;
}
