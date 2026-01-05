#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int n, ans;

vector<vector<int>> board;
queue<pair<int, vector<vector<int>>>> q;

int find_max(vector<vector<int>> &b) {
	int ans = 0;
	for (auto &row : b) {
		for (auto &col : row) {
			ans = max(ans, col);
		}
	}
	return ans;
}

vector<vector<int>> result(vector<vector<int>> b, int action) {
	if (action == 0) {
		for (int x = 0; x < n; x++) {
			queue<int> line;
			for (int y = 0; y < n; y++) {
				if (b[y][x] != 0) {
					line.push(b[y][x]);
					b[y][x] = 0;
				}
			}

			int idx = 0;
			while(!line.empty()) {
				int front = line.front(); line.pop();
				if (line.size() > 0) {
					if (front == line.front()) {
						line.pop();
						b[idx++][x] = front * 2;
					}
					else {
						b[idx++][x] = front;
					}
				}
				else {
					b[idx][x] = front;
				}
			}
		}
	}

	else if (action == 1) {
		for (int y = 0; y < n; y++) {
			queue<int> line;
			for (int x = 0; x < n; x++) {
				if (b[y][x] != 0) {
					line.push(b[y][x]);
					b[y][x] = 0;
				}
			}

			int idx = 0;
			while(!line.empty()) {
				int front = line.front(); line.pop();
				if (line.size() > 0) {
					if (front == line.front()) {
						line.pop();
						b[y][idx++] = front * 2;
					}
					else {
						b[y][idx++] = front;
					}
				}
				else {
					b[y][idx] = front;
				}
			}
		}
	}

	else if (action == 2) {
		for (int x = 0; x < n; x++) {
			queue<int> line;
			for (int y = n - 1; y >= 0; y--) {
				if (b[y][x] != 0) {
					line.push(b[y][x]);
					b[y][x] = 0;
				}
			}

			int idx = n - 1;
			while(!line.empty()) {
				int front = line.front(); line.pop();
				if (line.size() > 0) {
					if (front == line.front()) {
						line.pop();
						b[idx--][x] = front * 2;
					}
					else {
						b[idx--][x] = front;
					}
				}
				else {
					b[idx][x] = front;
				}
			}
		}
	}

	else if (action == 3) {
		for (int y = 0; y < n; y++) {
			queue<int> line;
			for (int x = n - 1; x >= 0; x--) {
				if (b[y][x] != 0) {
					line.push(b[y][x]);
					b[y][x] = 0;
				}
			}

			int idx = n - 1;
			while(!line.empty()) {
				int front = line.front(); line.pop();
				if (line.size() > 0) {
					if (front == line.front()) {
						line.pop();
						b[y][idx--] = front * 2;
					}
					else {
						b[y][idx--] = front;
					}
				}
				else {
					b[y][idx] = front;
				}
			}
		}
	}

	return b;
}

void solve() {
	q.push({0, board});

	while (!q.empty()) {
		auto [cnt, front] = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			auto temp = result(front, i);
			if (cnt + 1 > 5) continue;
			ans = max(ans, find_max(temp));
			q.push({cnt + 1, temp});
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;

	board.assign(n, vector<int>(n));

	for (auto &row : board) {
		for (auto &col : row) {
			cin >> col;
		}
	}

	ans = find_max(board);

	solve();

	cout << ans;
}