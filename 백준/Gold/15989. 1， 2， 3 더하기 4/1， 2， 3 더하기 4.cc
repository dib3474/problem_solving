#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int n;

vector<vector<long long int>> dp;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;

	v.assign(n, 0);
	
	for (auto &e : v) cin >> e;
	
	int max_value = max(4, *max_element(v.begin(), v.end()));

	dp.assign(max_value + 1, vector<long long int>(4));
	
	dp[1] = {0, 1, 0, 0};
	dp[2] = {0, 1, 1, 0};
	dp[3] = {0, 1, 1, 1};

	for (int i = 4; i <= max_value; i++) {
		dp[i][1] = 1;
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
	}

	for (auto e : v) cout << accumulate(dp[e].begin() + 1, dp[e].end(), 0) << '\n';
}