#include <iostream>
#include <algorithm>
using namespace std;

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int A[1000];
    int J[1000];
    fill_n(J, 1000, 1000);
    J[0] = 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        for (int j = 0; j < i; j++) {
            int gap = i - j;
            if (A[j] >= gap)
                J[i] = min(J[i], J[j] + 1);
        }
    }

    cout << ((J[N - 1] != 1000) ? J[N - 1] : -1);
}