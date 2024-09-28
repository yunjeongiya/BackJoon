#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define MAX 100000
int n;
long long arr[MAX];
long long sum = 0;
int i = 0;

void remove1() {
    sum += arr[i];
    i += 1;
}

void remove2() {
    sum += arr[i] * arr[i + 1];
    i += 2;
}


int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    i = 0;
    while (i < n) {
        if (arr[i] <= 0) {
            if (i + 1 < n && arr[i + 1] <= 0) {
                remove2();
            }
            else {
                remove1();
            }
            continue;
        }
        if (arr[i] == 1) {
            remove1();
            continue;
        }
        int leftNum = n - i;
        if (leftNum % 2 == 1) {
            remove1();
            continue;
        }
        remove2();
    }
    cout << sum;
}