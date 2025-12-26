#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<vector<int>> s(n, vector<int>(n));

	for (auto &row : s) for (auto &col : row) cin >> col;

	int min_val = 1e6;

	for (int i = 1; i <= (1 << n); i++) {
		vector<int> start;
		vector<int> link;
		int start_point = 0, link_point = 0;
		for (int j = 0; j < n; j++) {
			if ((i & (1 << j))) {
				for (int p : start) {
					start_point += s[p][j];
					start_point += s[j][p];
				}
				start.push_back(j);
			}
			else {
				for (int p : link) {
					link_point += s[p][j];
					link_point += s[j][p];
				}
				link.push_back(j);
			}
		}
		min_val = min(min_val, abs(start_point - link_point));
	}

	cout << min_val;
}