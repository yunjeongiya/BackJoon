#include <iostream>
#include <cmath>
using namespace std;
long long n;
bool check(unsigned long long x) {
    return pow(x,2) >= n;
}

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unsigned long long l, h, m;
    cin >> n;
    l = 0;
    h = n;
    while (l + 1 < h) {
        m = (l + h) / 2;
        if (check(l) == check(m)) l = m;
        if (check(h) == check(m)) h = m;
    }
    cout << h;
}