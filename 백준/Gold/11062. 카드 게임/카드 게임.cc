#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
vector<int> cards;

int play(int l, int r, int turn) {
    if (l > r) return 0;

    if (dp[l][r] != -1) return dp[l][r];

    if (turn == 0) {
        dp[l][r] = max(cards[l] + play(l + 1, r, 1), cards[r] + play(l, r - 1, 1));
    }
    else {
        dp[l][r] = min(play(l + 1, r, 0), play(l, r - 1, 0));
    }

    return dp[l][r];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        cards.assign(n, 0);
        for (auto& e : cards) cin >> e;

        dp.assign(n, vector<int>(n, -1));

        cout << play(0, n - 1, 0) << '\n';
    }
}