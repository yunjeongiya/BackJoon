#include<iostream>
#include<cmath>
using namespace std;

unsigned long long input;

long long sortcheck(unsigned long long x) {
    if (pow(x, 2) >= input) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    cin >> input;
    unsigned long long low = 0;
    unsigned long long hi = pow(2, 32);
    unsigned long long mid;
    while (true) {
        mid = (low + hi) / 2;

        if (low + 1 == hi) {
            if (sortcheck(low) == sortcheck(hi)) {
                cout << low;
                return 0;
            }
            cout << hi;
            return 0;
        }

        if (sortcheck(mid) == sortcheck(hi)) {
            hi = mid;
        }
        else {
            low = mid;
        }
    }
}