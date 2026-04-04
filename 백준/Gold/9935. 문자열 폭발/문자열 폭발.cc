#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string str;
    cin >> str;

    string bomb;
    cin >> bomb;
    reverse(bomb.begin(), bomb.end());

    stack<char> st;
    for (char e : str) {
        st.push(e);
        if (e == bomb[0]) {
            stack<char> temp;
            for (int i = 0; i < bomb.size(); i++) {
                if (!st.empty() && st.top() == bomb[i]) {
                    temp.push(st.top());
                    st.pop();
                }
                else {
                    while (!temp.empty()) {
                        st.push(temp.top());
                        temp.pop();
                    }
                }
            }
            if (temp.size() == bomb.size()) {
                while (!temp.empty()) {
                    temp.pop();
                }
            }
        }
    }
    vector<char> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    if (result.empty()) {
        cout << "FRULA";
    }
    else {
        reverse(result.begin(), result.end());
        for (auto e : result) {
            cout << e;
        }
    }
}