#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
bool visited[1001] = { false, };

void visit(int target) {
    if (visited[target]) return;
    cout << target << " ";
    visited[target] = true;
}

void sol() {
    int N, M, V;
    cin >> N >> M >> V;
    vector<vector<int>> G(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (auto& adjList : G) { //&안넣으면 adjList 복사 후 정렬해 원본 G는 영향x
        //번호 작은 정점부터 방문
        sort(adjList.begin(), adjList.end());
    }

    //dfs
    stack<int> S;
    S.push(V);
    while (!S.empty()) {
        int popped = S.top();
        S.pop();
        visit(popped);
        for (auto i = G[popped].rbegin(); i != G[popped].rend(); ++i) {
            if (!visited[*i]) S.push(*i);
        }
    }
    cout << '\n';
    //bfs
    fill_n(visited, 1001, false);
    queue<int> Q;
    Q.push(V);
    while (!Q.empty()) {
        int popped = Q.front();
        Q.pop();
        visit(popped);
        for (auto& i : G[popped]) {
            if (!visited[i]) Q.push(i);
        }
    }
}

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sol();
}