#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, t, e;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> change(n + 1);
        vector<int> rank, indeg(n + 1, 0);
        // rank 입력
        for (int i = 0; i < n; i++) {
            cin >> e;
            rank.push_back(e);
        }

        // indeg 설정
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                change[rank[i]].push_back(rank[j]);
                indeg[rank[j]]++;
            }
        }

        cin >> m;
        while (m--) {
            int a, b;
            cin >> a >> b;
            auto it = find(change[a].begin(), change[a].end(), b);
            if (it != change[a].end()) {
                change[a].erase(it);
                indeg[b]--;
                change[b].push_back(a);
                indeg[a]++;
            }
            else {
                it = find(change[b].begin(), change[b].end(), a);
                if (it != change[b].end()) {
                    change[b].erase(it);
                    indeg[a]--;
                    change[a].push_back(b);
                    indeg[b]++;
                }
            }
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indeg[rank[i]] == 0) {
                q.push(rank[i]);
            }
        }

        vector<int> result;

        while (!q.empty()) {
            int v = q.front(); q.pop();
            result.push_back(v);
            for (int u: change[v]) {
                indeg[u]--;
                if (indeg[u] == 0) q.push(u);
            }
        }


        if (result.size() != n) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            for (int e: result) {
                cout << e << ' ';
            }
            cout << '\n';
        }
    }    
}