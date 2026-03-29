#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> parent;

int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
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
    for (int i = 0; i <= n; i++) parent[i] = i;

    int ans;
    for (ans = 0; ans < m; ans++) {
        int a, b;
        cin >> a >> b;
        if (find(a) != find(b)) {
            merge(a, b);
        }
        else {
            break;
        }
    }
    if (ans == m) ans = -1;
    cout << ans + 1;
}