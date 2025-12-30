#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board(9, vector<int>(9));
vector<pair<int, int>> fill_list;

bool check(int y, int x, int n) {
	for (int i = 0; i < 9; i++) {
		if (board[i][x] == n && i != y) return false;
		if (board[y][i] == n && i != x) return false;
	}

	int section_y = 3 * (y / 3);
	int section_x = 3 * (x / 3);
	for (int i = section_y; i < section_y + 3; i++) {
		for (int j = section_x; j < section_x + 3; j++) {
			if (i == y && j == x) continue;
			if (board[y][x] == board[i][j]) return false;
		}
	}

	return true;
}

void solve(int idx) {
	if (idx == fill_list.size()) {
		for (int y = 0; y < 9; y++) {
			for (int x = 0; x < 9; x++) {
				cout << board[y][x] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}

	auto [y, x] = fill_list[idx];

	for (int i = 1; i <= 9; i++) {
		board[y][x] = i;
		if (check(y, x, i)) {
			solve(idx + 1);
		}
	}
	board[y][x] = 0;
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);


	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cin >> board[y][x];
			if (board[y][x] == 0) {
				fill_list.push_back({y, x});
			}
		}
	}

	solve(0);
}