#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);

    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<int> costs(n + 1, INF);

    int start, end;
    cin >> start >> end;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});
    costs[start] = 0;

    while(!pq.empty()) {
        auto [cost, now] = pq.top(); pq.pop();

        if (costs[now] < cost) continue;

        for (const auto& edge: graph[now]) {
            int c = cost + edge.second;
            if (c < costs[edge.first]) {
                costs[edge.first] = c;
                pq.push({c, edge.first});
            }
        }
    }
    cout << costs[end];
}