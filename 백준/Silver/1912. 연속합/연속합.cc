#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int max(vector<int>& vec) {
    int result = -1001;
    for (const int num : vec) {
        result = (num > result) ? num : result;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int& num : arr) {
        cin >> num;
    }
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max((dp[i-1] + arr[i]), arr[i]);
    }
    cout << max(dp) << '\n';
}