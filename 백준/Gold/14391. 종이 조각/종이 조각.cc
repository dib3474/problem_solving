#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> board;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> m;

	board.assign(n, vector<int>(m));
	
	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < m; j++) {
			board[i][j] = line[j] - '0';
		}
	}
	
	int max_sum = 0;
	for (int i = 0; i < (1 << (n * m)); i++) {
		int curr_sum = 0;
		
		for (int y = 0; y < n; y++) {
			int block_sum = 0;
			for (int x = 0; x < m; x++) {
				int k = y * m + x;
				if ((i & (1 << k)) == 0) {
					block_sum = block_sum * 10 + board[y][x];
				}
				else {
					curr_sum += block_sum;
					block_sum = 0;
				}
			}
			curr_sum += block_sum;
		}

		for (int x = 0; x < m; x++) {
			int block_sum = 0;
			for (int y = 0; y < n; y++) {
				int k = y * m + x;
				if ((i & (1 << k)) != 0) {
					block_sum = block_sum * 10 + board[y][x];
				}
				else {
					curr_sum += block_sum;
					block_sum = 0;
				}
			}
			curr_sum += block_sum;
		}

		max_sum = max(max_sum, curr_sum);
	}

	cout << max_sum;
}