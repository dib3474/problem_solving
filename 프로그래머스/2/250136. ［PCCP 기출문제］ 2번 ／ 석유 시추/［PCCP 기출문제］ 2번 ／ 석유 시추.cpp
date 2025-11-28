#include <bits/stdc++.h>
using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};


void bfs(const vector<vector<int>>& land, vector<vector<bool>>& visited, int n, int m, vector<int>& col) {
    if (visited[n][m]) return;
    if (!land[n][m]) return;
    int oil = 1, s = m, e = m;
    queue<pair<int, int>> q;
    q.push({n, m});
    visited[n][m] = true;
    while(!q.empty()) {
        auto [curr_y, curr_x] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int next_y = curr_y + dy[i];
            int next_x = curr_x + dx[i];
            if (next_y >= 0 && next_y < land.size() && next_x >=0 && next_x < land[0].size() &&
                !visited[next_y][next_x] && land[next_y][next_x]) {
                visited[next_y][next_x] = true;
                oil++;
                q.push({next_y, next_x});
                s = (s > next_x) ? next_x : s;
                e = (e < next_x) ? next_x : e;
            }
        }
    }
    for (int i = s; i <= e; i++) {
        col[i] += oil;
    }
}


int solution(vector<vector<int>> land) {
    vector<vector<bool>> visited(land.size(), vector<bool>(land[0].size()));
    vector<int> col(land[0].size());
    int answer = 0;
    for (int i = 0; i < land[0].size(); i++) {
        for (int j = 0; j < land.size(); j++) {
            bfs(land, visited, j, i, col);
        }
    }
    answer = *max_element(col.begin(), col.end());
    return answer;
}