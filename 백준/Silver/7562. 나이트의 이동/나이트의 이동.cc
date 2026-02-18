#include <bits/stdc++.h>
using namespace std;

int l;

int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};

vector<vector<int>> board;
vector<vector<int>> visited;

int bfs(pair<int, int> start, pair<int, int> end) {
    queue<pair<int, pair<int, int>>> q;

    q.push({0, start});
    visited[start.first][start.second] = 1;

    while (!q.empty()) {
        auto [cnt, front] = q.front(); q.pop();
        
        if (front == end) {
                return cnt;
            }

        for (int i = 0; i < 8; i++) {
            int next_y = front.first + dy[i];
            int next_x = front.second + dx[i];

            

            if (next_y >= 0 && next_y < l && next_x >= 0 && next_x < l && !visited[next_y][next_x]) {
                q.push({cnt + 1, {next_y, next_x}});
                visited[next_y][next_x] = 1;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> l;

        pair<int, int> start, end;
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;

        board.assign(l, vector<int>(l));
        visited.assign(l, vector<int>(l));

        int ans = bfs(start, end);

        cout << ans << '\n';
    }
}