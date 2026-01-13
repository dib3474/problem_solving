#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

vector<int> dp;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;

	dp.assign(n, 0);
	v.assign(n, 0);

	for (auto &e : v) cin >> e;

	dp[0] = v[0];

	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + v[i], v[i]);
	}

	cout << *max_element(dp.begin(), dp.end());
}