#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;

    char quack[] = {'q', 'u', 'a', 'c', 'k'};
    vector<int> ducks;
    for (auto i = 0; i < s.size(); i++) {
        if (s[i] == quack[0]) {
            if (ducks.empty()) {
                ducks.push_back(0);
            }
            else {
                int found = false;
                for (int j = 0; j < ducks.size(); j++) {
                    if (ducks[j] == 4) {
                        ducks[j] = 0;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    ducks.push_back(0);
                }
            }
        }
        else {
            int found = false;
            for (int k = 1; k < 5; k++) {
                if (s[i] == quack[k]) {
                    for (int j = 0; j < ducks.size(); j++) {
                        if (ducks[j] == k - 1) {
                            ducks[j] = k;
                            found = true;
                            break;
                        }
                    }
                }
                if (found) break;
            }
            if (!found) {
                cout << -1;
                return 0;
            }
        }
    }
    int fin = true;
    for (auto e : ducks) {
        if (e != 4) {
            fin = false;
        }
    }
    if (fin) {
        cout << ducks.size();
    }
    else {
        cout << -1;
    }
}