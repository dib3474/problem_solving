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
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    while (m--) {
        int c, a, b;
        cin >> c >> a >> b;

        if (c) {
            cout << ((find(a) == find(b)) ? "YES" : "NO") << '\n';
        }
        else {
            merge(a, b);
        }
    }
}