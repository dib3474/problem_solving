#include <iostream>
#include <vector>
using namespace std;

int n, ans = 0;
const int mod = 10007;

vector<int> dp(1001);

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i <= n; i++) {
		dp[i] = (dp[i-1] + dp[i-2]) % mod;
	}

	cout << dp[n];
}