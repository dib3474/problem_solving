#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, l;
    cin >> n >> l;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    deque<pair<int, int>> dq;

    for (int i = 1; i <= n; i++) {
        if (!dq.empty()) {
            if (dq.front().second < (i - l + 1)) {
                dq.pop_front();
            }
            while (!dq.empty() && dq.back().first > arr[i]) {
                    dq.pop_back();
            }
        }
        dq.push_back({arr[i], i});
        cout << dq.front().first << ' ';
    }
}