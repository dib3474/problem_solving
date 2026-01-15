#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int mod = 1000000009;

vector<long long int> dp;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;

	v.assign(n, 0);
	
	for (auto &e : v) cin >> e;
	
	int max_value = *max_element(v.begin(), v.end());

	dp.assign(max_value + 1, 0);
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= max_value; i++) {
		dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % mod;
	}

	for (auto e : v) cout << dp[e] << endl;;
}