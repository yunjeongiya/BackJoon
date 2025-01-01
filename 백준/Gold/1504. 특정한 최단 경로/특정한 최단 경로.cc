#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 1000000;
int N, E;
int s, e, c;
priority_queue<pii> pq;
vector<pii> adj[801];
int u, v;
int dist[801];
bool visited[801];

void reset() {
	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
		visited[i] = false;
	}
}

void dijkstra(int start) {
	reset();
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (visited[now])
			continue;
		visited[now] = true;
		for (auto& p : adj[now]) {
			int next = p.second;
			int nextcost = p.first + cost;
			if (nextcost < dist[next]) {
				dist[next] = nextcost;
				pq.push({ -nextcost, next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		cin >> s >> e >> c;
		adj[s].push_back({ c,e });
		adj[e].push_back({ c,s });
	}
	cin >> u >> v;

	dijkstra(1);
	bool flag1 = false;
	bool flag2 = false;

	int ans1 = dist[u];
	int ans2 = dist[v];
	if (dist[u] == INF)
		flag1 = true;
	if (dist[v] == INF)
		flag2 = true;
	dijkstra(u);
	ans1 += dist[v];
	ans2 += dist[N];
	if (dist[v] == INF)
		flag1 = true;
	if (dist[N] == INF)
		flag2 = true;
	dijkstra(v);
	ans1 += dist[N];
	ans2 += dist[u];
	if (dist[N] == INF)
		flag1 = true;
	if (dist[u] == INF)
		flag2 = true;
	if (flag1 && flag2) {
		cout << -1;
	}
	else if (flag1) {
		cout << ans2;
	}
	else if (flag2) {
		cout << ans1;
	}
	else {
		cout << min(ans1, ans2);
	}
}