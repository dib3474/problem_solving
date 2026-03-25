#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> apps(n), costs(n);
    for (auto& e : apps) cin >> e;
    
    int total_cost = 0;
    for (auto& e : costs) {
        cin >> e;
        total_cost += e;
    }

    vector<int> dp(total_cost + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = total_cost; j >= costs[i]; j--) {
            dp[j] = max(dp[j], dp[j - costs[i]] + apps[i]);
        }
    }

    for (int i = 0; i <= total_cost; i++) {
        if (dp[i] >= m) {
            cout << i;
            break;
        }
    }
}