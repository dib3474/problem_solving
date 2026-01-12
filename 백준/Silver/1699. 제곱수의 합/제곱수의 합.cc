#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;

vector<int> dp;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;

	dp.assign(n + 1, 0);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		int root = (int)sqrt(i);
		if (root * root == i) {
			dp[i] = min(dp[i], 1);
		}
		else {
			for (int j = 0; j <= int(sqrt(i)); j++) {
				dp[i] = min(dp[i], dp[i - j * j] + 1);
			}
		}
	}
	cout << dp[n];
}