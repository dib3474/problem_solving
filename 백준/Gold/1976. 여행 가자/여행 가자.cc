#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> parent;

int find(int i) {
    if (parent[i] == i) {
        return parent[i];
    }
    else {
        parent[i] = find(parent[i]);
    }
    return parent[i];
}

void merge(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[b] = a;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;

    parent.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int e;
            cin >> e;
            if (e) {
                merge(i, j);
            }
        }
    }

    vector<int> plan(m);
    for (auto& e : plan) cin >> e;
    for (int i = 0; i < m - 1; i++) {
        if (find(plan[i]) != find(plan[i + 1])) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    return 0;
}