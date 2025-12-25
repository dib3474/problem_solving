#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> b(n, vector<int>(n));
    vector<int> visited(n);
    iota(visited.begin(), visited.end(), 0);

    for (auto &row : b) {
        for (auto &col : row) {
            cin >> col;
        }
    }

    int min_val = 2e9;
    do {
        int val = 0, i;
        bool isValid = true;
        for (i = 0; i < n - 1; i++) {
            int dist = b[visited[i]][visited[i+1]];
            if (dist == 0) isValid = false;
            val += dist;
        }
        int dist = b[visited[i]][visited[0]];
        if (dist == 0) isValid = false;
        val += dist;
        if (!isValid) continue;
        min_val = min(min_val, val);
    } while(next_permutation(visited.begin(), visited.end()));

    cout << min_val << endl;
}