#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& e : arr) cin >> e;

    stack<pair<int, int>> st;

    long long ans = 0;

    for (auto e : arr) {
        while (!st.empty() && st.top().first < e) {
            ans += st.top().second;
            st.pop();
        }
        int cnt = 1;
        if (!st.empty()) {
            if (st.top().first == e) {
                cnt += st.top().second;
                ans += st.top().second;
                st.pop();
                if (!st.empty()) ans += 1;
            }
            else {
                ans += 1;
            }
        }

        st.push({e, cnt});
    }

    cout << ans;
}