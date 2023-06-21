#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sol() {
    int N, cnt = 0;
    cin >> N;
    vector<vector<int>> meetings(N, vector<int>(2));
    
    for (int i = 0; i < N; i++)
        cin >> meetings[i][0] >> meetings[i][1];

    sort(meetings.begin(), meetings.end(),
        [](vector<int> a, vector<int> b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });

    int occupied_until = 0;
    for (auto meeting : meetings) {
        if (meeting[0] < occupied_until) continue;
        occupied_until = meeting[1];
        cnt++;
    }
    cout << cnt;
}

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sol();
}