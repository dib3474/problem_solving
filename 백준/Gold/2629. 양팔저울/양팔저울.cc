#include <bits/stdc++.h>
using namespace std;

int n, t;

vector<int> weights;
vector<int> dp(40001, 0);

int main() {
    cin >> n;

    weights.assign(n, 0);
    for (auto& e : weights) cin >> e;

    dp[0] = 1;

    for (const auto &e : weights) {
        for (int j = 40000 - e; j >= 0; j--) {
            if (dp[j]) {
                dp[j + e] = 1;
            }
        }
        for (int j = 0; j <= 40000; j++) {
            if (dp[j]) {
                dp[abs(j - e)] = 1;
            }
        }
    }

    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        if (dp[n]) cout << 'Y' << ' ';
        else       cout << 'N' << ' ';
    }
}