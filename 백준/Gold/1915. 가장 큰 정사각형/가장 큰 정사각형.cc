#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define MAX 1000

int arr[MAX][MAX];
int getMin(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    }
    if (b <= c) {
        return b;
    }
    return c;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    int max = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
            if (arr[i][j] == 0) {
                continue;
            }
            if (i >= 1 && j >= 1) {
                arr[i][j] = getMin(arr[i-1][j], arr[i][j-1], arr[i-1][j-1]) + 1;
            }
            max = max > arr[i][j] ? max : arr[i][j]; // 1줄짜리 map인 경우 때문에 if 밖으로 뺌
        }
    }
    cout << max * max;
}