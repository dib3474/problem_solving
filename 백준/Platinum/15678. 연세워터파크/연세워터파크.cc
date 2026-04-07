#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, d;
    cin >> n >> d;

    vector<int> bridge(n), result(n);
    for (auto& e : bridge) cin >> e;

    deque<pair<int, long long>> dq;

    long long max_score = -1e9;

    for (int i = 0; i < n; i++) {
        long long current = bridge[i];
        if (!dq.empty()) {
            if (i - dq.front().first > d) dq.pop_front();
            if (!dq.empty()) {
                current = max(current, dq.front().second + bridge[i]);
            }
            while (!dq.empty() && dq.back().second <= current) {
                dq.pop_back();
            }
        }
        dq.push_back({i, current});
        max_score = max(max_score, current);
    }
    cout << max_score;
}