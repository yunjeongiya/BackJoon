#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int A, B;
        cin >> A >> B;
        cout << A+B << '\n';
    }
}