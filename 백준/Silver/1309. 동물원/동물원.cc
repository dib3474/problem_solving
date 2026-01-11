#include <iostream>
#include <vector>
using namespace std;

int n;
const int mod = 9901;

vector<int> dp;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;

	dp.assign(n + 1, 0);

	dp[0] = 1;
	dp[1] = 3;
	dp[2] = 7;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1] * 2) % mod;
	}
	cout << dp[n];
}