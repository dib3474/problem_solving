#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int n, m;
vector<vector<char>> board;
queue<pair<vector<vector<char>>, int>> q;
set<vector<vector<char>>> visited;
int ans = 11;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

vector<vector<char>> result(vector<vector<char>> b, int action) {
	int by, bx;
	int ry, rx;
	for (int curr_y = 0; curr_y < n; curr_y++) {
		for (int curr_x = 0; curr_x < m; curr_x++) {
			if (b[curr_y][curr_x] == 'R') {
				ry = curr_y;
				rx = curr_x;
				b[ry][rx] = '.';
			}
			if (b[curr_y][curr_x] == 'B') {
				by = curr_y;
				bx = curr_x;
				b[by][bx] = '.';
			}
		}
	}

	int B_dist = 0, R_dist = 0;
	while (b[by + dy[action]][bx + dx[action]] != '#') {
		by += dy[action];
		bx += dx[action];
		B_dist++;

		if (b[by][bx] == 'O') {
			break;
		}
	}

	while (b[ry + dy[action]][rx + dx[action]] != '#') {
		ry += dy[action];
		rx += dx[action];
		R_dist++;

		if (b[ry][rx] == 'O') {
			break;
		}
	}

	if(b[by][bx] == 'O') {
        return {};
    }

	if (b[ry][rx] != 'O') {
		if (by == ry && bx == rx) {
			if (B_dist > R_dist) {
				by -= dy[action];
				bx -= dx[action];
			}
			else {
				ry -= dy[action];
				rx -= dx[action];
			}
		}
        b[ry][rx] = 'R';
	}
	b[by][bx] = 'B';

	return b;
}

bool is_goal(vector<vector<char>> &b) {
	int check = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i][j] == 'B') check += 1;
			else if (b[i][j] == 'R') check += 2;
		}
	}
	return check == 1;
}

void solve() {
	q.push({board, 0});
	visited.insert(board);

	while (!q.empty()) {
		auto [front, cnt] = q.front(); q.pop();

		if (cnt > 10) {
			continue;;
		}

		for (int i = 0; i < 4; i++) {
			auto tmp = result(front, i);

			if (tmp.empty()) continue;

			if (is_goal(tmp)) {
				ans = cnt + 1;
				return ;
			}

			if (visited.find(tmp) == visited.end()) {
				q.push({tmp, cnt + 1});
				visited.insert(tmp);
			}
		}
	}
	
}


int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> m;

	board.assign(n, vector<char>(m));
	
	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < m; j++) {
			board[i][j] = line[j];
		}
	}
	
	solve();

	ans = (ans == 11) ? -1 : ans;

	cout << ans;
}