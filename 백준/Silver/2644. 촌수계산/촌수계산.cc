#include <iostream>
#include <vector>
using namespace std;

vector<int> visited;
vector<vector<int>> graph;
int a, b, result = -1;

void dfs(int start, int depth) {
    if (start == b) {
        result = depth;
        return;
    }
    visited[start] = 1;

    for (auto e : graph[start]) {
        if (!visited[e]) {
            dfs(e, depth + 1);
        }
    }
}

int main() {
    int n;
    int m;
    cin >> n >> a >> b >> m;

    graph.assign(n + 1, vector<int>());
    visited.assign(n + 1, 0);
    
    while (m--) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(a, 0);
    
    cout << result << '\n';
}