#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<vector<int>>> t = {
	{{1, 1, 1, 1}}, 
	{{1}, 
	 {1}, 
	 {1},
	 {1},},
	{{1, 1},
	 {1, 1}},
	{{1, 0},
	 {1, 0},
	 {1, 1}},
	{{0, 1},
	 {0, 1},
	 {1, 1}},
	{{1, 1},
	 {1, 0},
	 {1, 0}},
	{{1, 1},
	 {0, 1},
	 {0, 1}},
	{{1, 1, 1},
	 {1, 0, 0}},
	{{1, 0, 0},
	 {1, 1, 1}},
	{{1, 1, 1},
	 {0, 0, 1}},
	{{0, 0, 1},
	 {1, 1, 1}},
	{{0, 1, 1},
	 {1, 1, 0}},
	{{1, 1, 0},
	 {0, 1, 1}},
	{{1, 0},
	 {1, 1},
	 {0, 1}},
	{{0, 1},
	 {1, 1},
	 {1, 0}},
	{{1, 1, 1},
	 {0, 1, 0}},
	{{0, 1, 0},
	 {1, 1, 1}},
	{{1, 0},
	 {1, 1},
	 {1, 0}},
	{{0, 1},
	 {1, 1},
	 {0, 1}}
};

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> board(n, vector<int>(m));
	for (auto &row : board) {
		for (auto &col : row) {
			cin >> col;
		}
	}
	int sum_max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < t.size(); k++) {
				int value = 0;
				for (int l = 0; l < t[k].size(); l++) {
					for (int o = 0; o < t[k][l].size(); o++) {
						if (i + l < n && j + o < m && t[k][l][o] == 1) {
							value += board[i + l][j + o];
						}
					}
				}
				sum_max = max(sum_max, value);
			}
		}
	}

	cout << sum_max;
}