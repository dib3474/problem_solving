#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& e : arr) cin >> e;

    stack<pair<int, int>> st;

    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            st.push({arr[i], i});
        }
        else {
            auto [hight, index] = st.top();
            if (hight > arr[i]) { // 작아졌을 때
                while (!st.empty() && st.top().first > arr[i]) {
                    hight = st.top().first;
                    index = st.top().second;
                    ans = max(ans, hight * (i - index));
                    st.pop();
                }
                st.push({arr[i], index});
            }
            else if (hight < arr[i]) {
                st.push({arr[i], i});
            }
        }

        if (i == n - 1) {
            while (!st.empty()) {
                auto [hight, index ] = st.top();
                ans = max(ans, hight * (n - index));
                st.pop();
            }
        }
    }
    cout << ans;
}