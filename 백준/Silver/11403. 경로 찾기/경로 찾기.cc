#include <iostream>
#include <vector>
using namespace std;

int n;

vector<vector<int>> board;
vector<vector<int>> visited;

void solve() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j] = board[i][j] || (board[i][k] && board[k][j]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;

	board.assign(n, vector<int>(n));

	for (auto& row : board) {
		for (auto& col : row) {
			cin >> col;
		} 
	}
	
	solve();
	
	for (auto& row : board) {
		for (auto& col : row) {
			cout << col << ' ';
		}
		cout << '\n';
	}
}