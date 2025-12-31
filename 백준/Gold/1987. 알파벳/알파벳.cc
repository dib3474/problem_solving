#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;

vector<vector<char>> board;
vector<int> visited(26, 0);
int max_dist = 0;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void solve(int y, int x, int count) {
	max_dist = max(max_dist, count);

	for (int i = 0; i < 4; i++) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];

		if (next_y >= 0 && next_y < n && next_x >= 0 && next_x < m) {
			int idx = board[next_y][next_x] - 'A';

			if (!visited[idx]) {
				visited[idx] = 1;
				solve(next_y, next_x, count + 1);
				visited[idx] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> m;

	board.assign(n, vector<char>(m));

	for (auto &row : board) {
		for (auto &col : row) {
			cin >> col;
		}
	}

	int idx = board[0][0] - 'A';
	visited[idx] = 1;

	solve(0, 0, 1);

	cout << max_dist;
}