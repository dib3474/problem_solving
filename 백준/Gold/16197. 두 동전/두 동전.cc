#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;

vector<vector<char>> board;
queue<pair<vector<pair<int, int>>, int>> q;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs() {
	while(!q.empty()) {
		auto [front, cnt] = q.front();
		q.pop();

		if (cnt > 10) {
			cout << -1;
			return;
		}
		
		for (int i = 0; i < 4; i++) {
			vector<pair<int, int>> tmp;
			for (auto [curr_y, curr_x] : front) {
				int next_y = curr_y + dy[i];
				int next_x = curr_x + dx[i];

				if (next_y >= 0 && next_y < n && next_x >= 0 && next_x < m) {
					if (board[next_y][next_x] == '#')
						tmp.push_back({curr_y, curr_x});
					else 
						tmp.push_back({next_y, next_x});
				}
			}
			
			if (tmp.size() == 2) {
				q.push({tmp, cnt + 1});
			}
			else if (tmp.size() == 1) {
				if (cnt + 1 > 10) cout << -1;
				else cout << cnt + 1;
				return;
			}
		}
	}
	cout << -1;
}

int main() {
	cin >> n >> m;

	board.assign(n, vector<char>(m));
	
	vector<pair<int, int>> tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'o')
				tmp.push_back({i, j});
		}
	}
	q.push({tmp, 0});
	
	bfs();
}