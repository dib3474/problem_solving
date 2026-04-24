#include <iostream>
#include <vector>
using namespace std;

struct coordinate {
    int x;
    int y;
};

int main() {
    vector<coordinate> p(3);
    for(auto& [x, y] : p) {
        cin >> x >> y;
    }

    coordinate v1 = {p[1].x - p[0].x, p[1].y - p[0].y};
    coordinate v2 = {p[2].x - p[1].x, p[2].y - p[1].y};

    int clock = v1.x * v2.y - v1.y * v2.x;

    if      (clock >  0) cout << 1 << endl;
    else if (clock == 0) cout << 0 << endl;
    else if (clock <  0) cout << -1 << endl;
}