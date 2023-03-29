#include <iostream>
#include <algorithm>
using namespace std;

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, A[100000], M, X;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A, A + N);
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> X;
        cout << (int)binary_search(A, A + N, X) << "\n";
    }
    return 0;
}