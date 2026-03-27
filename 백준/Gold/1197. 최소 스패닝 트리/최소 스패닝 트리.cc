#include <bits/stdc++.h>
using namespace std;

int v, e;

struct graph {
    int a;
    int b;
    int c;
};

vector<int> parent;
vector<graph> arr;

bool compare(graph a, graph b) {
    return a.c < b.c;
}

int find(int i) {
    if (parent[i] == i) {
        return i;
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
    cin >> v >> e;

    parent.assign(v + 1, 0);

    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        arr.push_back({a, b, c});
    }

    sort(arr.begin(), arr.end(), compare);

    int ans = 0;

    for (const auto& [a, b, c] : arr) {
        if (find(a) != find(b)) {
            merge(a, b);
            ans += c;
        }
    }

    cout << ans;
}