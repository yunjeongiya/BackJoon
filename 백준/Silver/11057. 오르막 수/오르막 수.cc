#include <iostream>
#define DIV 10007
using namespace std;
int N;

void dp(int* cnt) {
    for (int i = 0; i < 10; i++) {
        cnt[i] %= DIV;
        for (int j = i + 1; j < 10; j++) {
            cnt[i] += cnt[j];
        }
    }
}

void sol() {
    cin >> N;
    int cnt[10];
    fill_n(cnt, 10, 1);

    while(N--) dp(cnt);

    cout << cnt[0] % DIV;
}

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sol();
}