#include <iostream>
#include <vector>
using namespace std;

int n;
const int mod = 1000000000;

vector<vector<long long int>> dp(101, vector<long long int>(10));

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) { 
				dp[i][0] = dp[i - 1][1] % mod;
			}
			else if (j == 9) {
				dp[i][9] = dp[i - 1][8] % mod;
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
			}
		}
	}
	long long int total_sum = 0;
	for (int i = 0; i <= 9; i++) {
		total_sum += dp[n][i] % mod;
	}

	cout << total_sum % mod;
}