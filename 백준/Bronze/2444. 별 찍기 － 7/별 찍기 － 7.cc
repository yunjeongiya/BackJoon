#include <iostream>
using namespace std;
#define endl '\n'
void sol() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N - i; j++)
            cout << ' ';
        for (int j = 1; j <= 1 + 2 * (i - 1); j++)
            cout << '*';
        cout << endl;
    }
    for (int i = N-1; i >= 1; i--) {
        for (int j = 1; j <= N - i; j++)
            cout << ' ';
        for (int j = 1; j <= 1 + 2 * (i - 1); j++)
            cout << '*';
        cout << endl;
    }
}
int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sol();
}