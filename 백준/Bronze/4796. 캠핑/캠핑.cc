#include <iostream>
using namespace std;

void sol() {
    int L, P, V, cnt=0;
    while (true) {
        cin >> L >> P >> V;
        if (L == 0) break;
        cout << "Case " << ++cnt << ": " << ((int)(V / P)) * L + min(V % P, L) << '\n';
    }
}

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sol();
}