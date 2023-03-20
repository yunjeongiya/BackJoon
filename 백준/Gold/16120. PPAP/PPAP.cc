#include<iostream>
#include<string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cnt = 0;
    string s;

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'P') {
            cnt++;
            continue;
        }
        if (s[i] == 'A' && s[i + 1] == 'P' && cnt > 1) {
            cnt--;
            i++;
        }
        else {
            cout << "NP";
            return 0;
        }
    }
    if (cnt == 1) cout << "PPAP";
    else cout << "NP";
}