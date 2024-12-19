#include <iostream>
using namespace std;

int main(void){
    cout.tie(0);
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cout << i << '\n';
    }
}