#include <iostream>
#include <unordered_map>
#include <stack>
#define endl '\n'
#define int long long
using namespace std;

int32_t main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, P, Q;
    cin >> N >> P >> Q;
    
    unordered_map<int, int> A;
    A[0] = 1;

    stack<int> s;
    s.push(N);
    
    while (!s.empty()) {
        int i = s.top();
        
        // A[i]가 이미 계산되었거나 i가 0이면 스택에서 제거
        if (A.find(i) != A.end()) {
            s.pop();
            continue;
        }
        
        // A[i/P]와 A[i/Q]가 모두 계산된 경우
        if (A.find(i / P) != A.end() && A.find(i / Q) != A.end()) {
            A[i] = A[i / P] + A[i / Q];
            s.pop();  // 처리 완료 후 pop
        } else {
            // 아직 계산되지 않았다면 먼저 i/P, i/Q를 계산하기 위해 스택에 push
            if (A.find(i / P) == A.end() && i / P > 0) s.push(i / P);  // i / P가 0 이상일 때만 push
            if (A.find(i / Q) == A.end() && i / Q > 0) s.push(i / Q);  // i / Q가 0 이상일 때만 push
        }
    }
    
    cout << A[N] << endl;
}
