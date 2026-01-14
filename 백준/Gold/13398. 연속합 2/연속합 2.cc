#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

vector<vector<int>> dp;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;

	dp.assign(n, vector<int>(2, -1e9));
	v.assign(n, 0);

	for (auto &e : v) cin >> e;

	dp[0][0] = v[0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0] + v[i], v[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + v[i]);
	}

	int ans = -1e9;
	for (auto &e : dp) {
		ans = max(ans, *max_element(e.begin(), e.end()));
	}

	cout << ans;
}