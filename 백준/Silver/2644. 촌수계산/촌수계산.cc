#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int n, x, y, m;

vector<vector<int>> graph;
vector<int> visited;
vector<int> parent;
vector<pair<int, int>> arr;

int result = -1;

void dfs(int v, int dep) {
    if (v == y) {
        result = dep;
        return;
    }

    visited[v] = 1;

    for (int e : graph[v]) {
        if (!visited[e]) {
            dfs(e, dep + 1);
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> x >> y >> m;

	graph.assign(n + 1, vector<int>());
	visited.assign(n + 1, 0);
	parent.assign(n + 1, 1);

	parent[0] = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		parent[b] = 0;
	}

	auto it = find(parent.begin(), parent.end(), 1);
	
	dfs(x, 0);

	cout << result;
}