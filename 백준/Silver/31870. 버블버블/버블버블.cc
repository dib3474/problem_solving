#include <bits/stdc++.h>
using namespace std;

int bubble_sort(vector<int> arr) {
    int ans = 0;
    for (int i = arr.size() - 1; i > 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto & e: arr) cin >> e;

    int ans1 = bubble_sort(arr);

    reverse(arr.begin(), arr.end());

    int ans2 = bubble_sort(arr) + 1;
    
    cout << min(ans1, ans2);
}