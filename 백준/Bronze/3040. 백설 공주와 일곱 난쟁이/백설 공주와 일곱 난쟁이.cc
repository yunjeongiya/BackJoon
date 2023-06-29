#include <iostream>
using namespace std;
#define endl '\n'
void sol() {
    int hats[9], overflow = -100;
    for (int i = 0; i < 9; i++) {
        cin >> hats[i];
        overflow += hats[i];
    }
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (hats[i] + hats[j] == overflow) {
                for (int k = 0; k < 9; k++) {
                    if (k != i && k != j) cout << hats[k] << endl;
                }
                return;
            }
        }
    }
}

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sol();
}