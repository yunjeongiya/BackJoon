#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

void sol() {
    int N;
    cin >> N;
    vector<pair<int, int>> meetings(N);
    
    for (int i = 0; i < N; i++)
        cin >> meetings[i].first >> meetings[i].second;

    sort(meetings.begin(), meetings.end(),
        [](pair<int, int> a, pair<int, int> b) {
            return a.second == b.second ?
                a.first < b.first : a.second < b.second;
        });

    int occupied_until = 0, cnt = 0;
    for (auto meeting : meetings) {
        if (meeting.first < occupied_until) continue;
        occupied_until = meeting.second;
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