#include <iostream>
#include <string>
#include <queue>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs(vector<vector<int>>& maze, vector<vector<int>>& distance) {
    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()) {
        auto [curr_y, curr_x] = q.front(); q.pop();

        if(maze[curr_y][curr_x]) {
            // maze[curr_y][curr_x] = 0;
            for(int i = 0; i < 4; i++) {
                int new_y = curr_y + dy[i];
                int new_x = curr_x + dx[i];
                if (new_y < 0 || new_y >= maze.size() ||  new_x < 0 || new_x >= maze[0].size()) continue;
                if (distance[new_y][new_x] != 0) continue;
                q.push({new_y, new_x});
                distance[new_y][new_x] = distance[curr_y][curr_x] + 1;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> maze(n, vector<int>(m));
    vector<vector<int>> distance(n, vector<int>(m));

    for(auto &row : maze) {
        string line;
        cin >> line;
        for(int j = 0; j < m; j++) {
            row[j] = line[j] - 48;
        }
    }

    bfs(maze, distance);
    cout << distance[n-1][m-1] + 1;
}