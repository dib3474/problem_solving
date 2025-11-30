#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> students(n + 1);
    vector<int> indeg(n + 1, 0);
    while (m--) {
        int a, b;
        cin >> a >> b;
        
        students[a].push_back(b);
        indeg[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int v = q.front(); q.pop();
        cout << v << " ";
        for (int e : students[v]) {
            indeg[e]--;
            if (indeg[e] == 0) {
                q.push(e);
            }
        }
    }
}