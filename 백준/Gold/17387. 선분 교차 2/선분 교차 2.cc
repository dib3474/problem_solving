#include <iostream>
#include <vector>
using namespace std;

struct coordinate {
    long long x;
    long long y;

    bool operator < (const coordinate& other) const {
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }

    bool operator <= (const coordinate& other) const {
        if (x == other.x) {
            return y <= other.y;
        }
        return x <= other.x;
    }
};

int ccw(coordinate v1, coordinate v2) {
    long long result = v1.x * v2.y - v1.y * v2.x;
    if (result > 0) return 1;
    else if (result == 0) return 0;
    else return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<coordinate> p(4);
    for(auto& [x, y] : p) {
        cin >> x >> y;
    }

    if (p[1] < p[0]) swap(p[0], p[1]);
    if (p[3] < p[2]) swap(p[2], p[3]);

    coordinate v1 = {p[1].x - p[0].x, p[1].y - p[0].y};
    coordinate v2 = {p[2].x - p[1].x, p[2].y - p[1].y};
    coordinate v3 = {p[3].x - p[1].x, p[3].y - p[1].y};

    coordinate v4 = {p[3].x - p[2].x, p[3].y - p[2].y};
    coordinate v5 = {p[0].x - p[3].x, p[0].y - p[3].y};
    coordinate v6 = {p[1].x - p[3].x, p[1].y - p[3].y};

    int cond1 = ccw(v1, v2) * ccw(v1, v3);
    int cond2 = ccw(v4, v5) * ccw(v4, v6);

    int result = -1;
    if (cond1 <= 0 && cond2 <= 0) {
        if (cond1 == 0 && cond2 == 0) {
            if (p[0] <= p[3] && p[2] <= p[1]) {
                result = 1;
            } else {
                result = 0;
            }
        }
        else {
            result = 1;
        }
    } 
    else {
        result = 0;
    }

    cout << result << '\n';
}