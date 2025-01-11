#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int cmp(string a, string b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    return a.size() < b.size();
}
int main(void){
    int N;
    cin >> N;
    vector<string> strings(N);
    for(int i = 0; i < N; i++) {
        cin >> strings[i];
    }
    sort(strings.begin(), strings.end(), cmp);

    string pre = "";
    for(auto str : strings) {
        if (str.compare(pre) == 0) continue;
        cout << str << '\n';
        pre = str;
    }
}