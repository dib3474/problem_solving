#include <bits/stdc++.h>
using namespace std;

int t, f;
unordered_map<string, string> parent;
unordered_map<string, int> parent_size;

string find(string i) {
    if (parent.count(i) == 0) {
        parent[i] = i;
        parent_size[i] = 1;
    }
    if (parent[i] == i) {
        return i;
    }
    return parent[i] = find(parent[i]);
}

int merge(string i, string j) {
    string a = find(i);
    string b = find(j);
    if (a != b) {
        parent[b] = a;
        parent_size[a] += parent_size[b];
    }

    return parent_size[a];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;

    while (t--) {
        int f;
        cin >> f;
        parent.clear();
        parent_size.clear();
        while (f--) {
            string a, b;
            cin >> a >> b;
            cout << merge(a, b) << '\n';
        }
    }
}