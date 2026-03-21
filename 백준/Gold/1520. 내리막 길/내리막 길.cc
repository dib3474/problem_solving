#include <bits/stdc++.h>
using namespace std;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

int m, n;

vector<vector<int>> board;
vector<vector<int>> dp;

int dfs(int y, int x) {
    if (y == m - 1 && x == n - 1) {
        return 1;
    }

    if (dp[y][x] != -1) {
        return dp[y][x];
    }

    dp[y][x] = 0;

    for (int i = 0 ; i < 4; i++) {
        int next_y = y + dy[i];
        int next_x = x + dx[i];

        if (next_y >= 0 && next_y < m && next_x >= 0 && next_x < n) {
            if (board[next_y][next_x] < board[y][x]) {
                dp[y][x] += dfs(next_y, next_x);
            }
        }
    }

    return dp[y][x];
}

int main() {
    cin >> m >> n;
    
    board.assign(m, vector<int>(n));
    dp.assign(m, vector<int>(n, -1));

    for (auto& row : board) {
        for (auto& col : row) cin >> col;
    }

    cout << dfs(0, 0) << '\n';
}