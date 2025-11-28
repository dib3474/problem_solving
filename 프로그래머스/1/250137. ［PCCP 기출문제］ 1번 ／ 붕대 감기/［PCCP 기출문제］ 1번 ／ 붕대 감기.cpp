#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int time = 1, combo = 0, max_health = health;
    for (auto attack: attacks) {
        while(time < attack[0]) {
            time++;
            combo++;
            if (combo == bandage[0]) {
                health += bandage[2];
                combo = 0;
            }
            health += bandage[1];
        }
        if (health > max_health) health = max_health;
        health -= attack[1];
        time++;
        combo = 0;
        cout << time << ' ' << health << ' ' << combo << '\n';
        if (health <= 0) return -1;
    }
    return health;
}