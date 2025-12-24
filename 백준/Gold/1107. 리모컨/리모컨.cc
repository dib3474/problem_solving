#include <iostream>

using namespace std;
int broken[10] = {0,};

int check(int n) {
    if (n == 0) {
        if (broken[0]) return 0;
        else return 1;
    }
    int len = 0;
    while(n) {
        if (broken[n%10] == 1) return 0;
        len++;
        n/=10;
    }
    return len;
}

int main() {
    int N, ans=123456789;
    cin >> N;
    
    ans = N-100;
    if (ans<0) ans=-ans;

    
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int temp;
        cin >> temp;
        broken[temp] = 1;
    };
    for (int i=0; i<1000000; i++) {
        int ch = i;
        int len = check(ch);
        if (len > 0) {
            int press = ch - N;
            if (press < 0) press = -press;

            if (ans > len + press) ans = len + press;
        }
    }
    cout << ans << '\n';
    return 0;
}