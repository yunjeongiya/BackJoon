#include <iostream>
using namespace std;
#define endl '\n'
#define NMAX 100000

struct UnionFind {
	int groups[NMAX + 1];
	int rank[NMAX + 1];
	UnionFind(int n) {
		for (int i = 1; i <= n; i++) {
			groups[i] = i;
			rank[i] = 1;
		}
	}
	int findGroup(int u) {
		if (groups[u] == u) return u;
		return groups[u] = findGroup(groups[u]);
	}
	bool areInSameGroup(int u, int v) {
		return findGroup(u) == findGroup(v);
	}
	void merge(int u, int v) {
		u = findGroup(u);  // u의 대표 노드 찾기
		v = findGroup(v);  // v의 대표 노드 찾기

		if (u == v) return;  // 이미 같은 그룹이면 종료
		if (rank[u] > rank[v]) 
			swap(u, v); // 무조건 rank[u] <= rank[v] 되도록
		groups[u] = v; // v 아래에 u 그룹 붙이기
		if (rank[u] == rank[v]) ++rank[v];
	}
};

int32_t main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	UnionFind unionFind = UnionFind(N);

	int groupCnt = N;
	int uselessCnt = 0;
	while (M--) {
		int u, v;
		cin >> u >> v;
		if(unionFind.areInSameGroup(u, v)) {
			uselessCnt++;
		}
		else {
			unionFind.merge(u, v);
			groupCnt--;
		}
	}
	cout << uselessCnt + groupCnt - 1;
}