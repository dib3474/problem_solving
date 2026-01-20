#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int n, m, v;

vector<vector<int>> graph;
vector<int> visited;

void dfs(int v) {
	if (visited[v]) return ;
	
	cout << v << ' ';
	
	visited[v] = 1;

	for (int e : graph[v]) {
		dfs(e);
	}
}

void bfs(int v) {
	visited.assign(n + 1, 0);
	queue<int> q;
	q.push(v);
	visited[v] = 1;

	while (!q.empty()) {
		int f = q.front(); q.pop();
		cout << f << ' ';
		for (int e : graph[f]) {
			if (!visited[e]) {
				q.push(e);
				visited[e] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> m >> v;

	graph.assign(n + 1, vector<int>());
	visited.assign(n + 1, 0);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v);
	cout << '\n';
	bfs(v);
}