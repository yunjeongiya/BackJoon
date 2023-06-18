#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define KMAX 10000
long long K, N, l, m, h;
vector<int> lens(KMAX);

bool check(int x) {
    long long cnt = 0;
    // lens[i]/x <= 2^31-1(INT_MAX) 이므로 여러개 더해지면 cnt 범위 int 초과
    for (int i = 0; i < K; i++) {
        cnt += lens[i] / x;
    }
    return cnt >= N;
}

void sol() {
    cin >> K >> N;
    // 1<=len<=2^31-1
    l = 1;
    h = pow(2, 31);
    for (int i = 0; i < K; i++) {
        cin >> lens[i];
        //h = min(h, lens[i]); // 범위 안좁혀도 큰 상관x
    }

    while (l + 1 < h) {
        m = ((long long)l + h) / 2; // h=2^31-1(INT_MAX) 면 l+h가 int 범위 초과
        // cout << "l: " << l << "m: " << m << "h: " << h << endl;
        if (check(l) == check(m)) l = m;
        if (check(h) == check(m)) h = m;
    }
    cout << l;
}

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sol();
}