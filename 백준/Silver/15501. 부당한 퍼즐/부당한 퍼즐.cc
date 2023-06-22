#include <iostream>
using namespace std;
#define nMAX 1000000
void sol() {
    int n, i, offset;
    cin >> n;
    int a[nMAX], b[nMAX]; // 모든 수는 1부터 n 사이, 한번만 나타남
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++) {
        cin >> b[i];
        if (a[0] == b[i]) offset = i;
    }

    for (i = 0; i < n; i++) {
        int j = (offset + i + n) % n;
        if (a[i] != b[j]) break;
    }
    if (i == n) {
        cout << "good puzzle";
        return;
    }

    for (i = 0; i < n; i++) {
        int j = (offset - i + n) % n;
        if (a[i] != b[j]) break;
    }
    if (i == n) {
        cout << "good puzzle";
        return;
    }

    cout << "bad puzzle";
}

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sol();
}