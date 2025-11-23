#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 1e8;

int main() {
    int V, E, start;
    cin >> V >> E >> start;
    vector<vector<pair<int, int>>> graph(V + 1);
    while(E--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<int> distance(V + 1, INF);
    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});
    
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > distance[u]) continue;

        for (auto [v, w]: graph[u]) {
            if (distance[v] > distance[u] + w) {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (distance[i] == INF) cout << "INF" << '\n';
        else cout << distance[i] << '\n';
    }
}