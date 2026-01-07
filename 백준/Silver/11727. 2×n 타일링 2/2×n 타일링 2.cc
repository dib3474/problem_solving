#include <iostream>
#include <vector>
using namespace std;

int n, ans = 0;
const int mod = 10007;

vector<int> dp;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;
	dp.assign(n+1, 0);
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i-1] + (2 * dp[i-2])) % mod;
	}

	cout << dp[n];
}