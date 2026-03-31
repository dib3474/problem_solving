#include <bits/stdc++.h>
using namespace std;

struct Cost {
    int red;
    int green;
    int blue;
};

int n;

vector<Cost> v;
vector<vector<int>> dp;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int red, green, blue;
        cin >> red >> green >> blue;
        v[i] = {red, green, blue};
    }
    dp.assign(n + 1, vector<int>(3));
    dp[1][0] = v[1].red;
    dp[1][1] = v[1].green;
    dp[1][2] = v[1].blue;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + v[i].red;
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + v[i].green;
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + v[i].blue;
    }

    cout << *min_element(dp[n].begin(), dp[n].end());
}