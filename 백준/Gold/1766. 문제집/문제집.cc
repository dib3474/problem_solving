#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> problems(n + 1);
    vector<int> indeg(n + 1, 0);
    while (m--) {
        int a, b;
        cin >> a >> b;
        
        problems[a].push_back(b);
        indeg[b]++;
    }

    priority_queue<int, vector<int>, greater<>> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int v = q.top(); q.pop();
        cout << v << ' ';
        for (int u: problems[v]) {
            indeg[u]--;
            if (indeg[u] == 0) q.push(u);
        }
    }
}