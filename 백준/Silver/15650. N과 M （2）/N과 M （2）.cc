#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define MAX 9

int n, m;
int arr[MAX];
bool is_used[MAX];

void func(int cnt) {
    if (cnt == m + 1) { // 종료 조건
        for (int i = 1; i <= m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = arr[cnt-1] + 1; i <= n; i++) {
        if (!is_used[i]) {
            arr[cnt] = i;
            is_used[i] = true;
            func(cnt + 1);
            is_used[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    func(1);
}