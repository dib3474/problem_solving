#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int total = 0;
    int star_idx = -1;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '*') {
            total += ((s[i] - '0') * ((i % 2 == 0) ? 1 : 3));
        }
        else {
            star_idx = i;
        }
    }

    for (int digit = 0; digit <= 9; digit++) {
        int weight = (star_idx % 2 == 0) ? 1 : 3;
        if ((total + digit * weight) % 10 == 0) {
            cout << digit;
            break;
        }
    }
}