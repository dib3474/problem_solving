#include <bits/stdc++.h>
using namespace std;

const int max_value = 987654321;

int get_file_sum_size(vector<int> c, int i, int j) {
    int ans = 0;
    for (int k = i; k <= j; k++) {
        ans += c[k];
    } 
    return ans;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int K;
        cin >> K;

        vector<int> c(K);
        vector<vector<int>> dp(K, vector<int>(K));
        for (auto &e : c) cin >> e;

        for (int j = 0; j < K; j++) {
            for (int i = j - 1; i >= 0; i--) {
                int ans = max_value;
                int file_sum_size = get_file_sum_size(c, i, j);
                for (int k = i; k < j; k++) {
                    ans = min(ans, dp[i][k] + dp[k+1][j] + file_sum_size);
                }
                dp[i][j] = ans;
            }
        }
        cout << dp[0][K - 1] << '\n';
    }
}