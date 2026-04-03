#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& e : arr) cin >> e;

    stack<int> s;
    vector<int> result(n);

    for (int i = n - 1; i >= 0; i--) {
        if (s.empty()) {
            result[i] = -1;
            s.push(arr[i]);
        }
        else {
            while (!s.empty()) {
                if (s.top() > arr[i]) {
                    result[i] = s.top();
                    s.push(arr[i]);
                    break;
                }
                else {
                    s.pop();
                }
            }
            if (s.empty()) {
                result[i] = -1;
                s.push(arr[i]);
            }
        }
    }

    for (auto e : result) cout << e << ' ';
}