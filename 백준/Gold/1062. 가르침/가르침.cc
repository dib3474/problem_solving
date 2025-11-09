#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, result = 0;
    cin >> n >> k;
    vector<int> str(n);
    for (int& e : str) {
        string line;
        cin >> line;
        for (char c : line) {
            e = e | (1 << ( c - 'a'));
        }
    }
    
    for (int i = 1; i < (1 << 26); i++) {
        int count = 0;
        if (__builtin_popcount(i) == k) {
            for (int e: str) {
                if ((e & ~i) == 0) {
                    count++;
                }
            }
            result = max(result, count);
        }
    }
    cout << result;

}