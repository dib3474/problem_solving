#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    int n, m, v;
    cin >> n >> m >> v;

    vector<vector<int>> graph(n+1);
    
    while(m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    stack<int> dfs;
    vector<bool> visited(n+1, false);
    dfs.push(v);
    while(!dfs.empty()) {
        int top = dfs.top(); dfs.pop();
        if (visited[top]) continue;
        visited[top] = true;
        
        cout << top << " ";
        sort(graph[top].begin(), graph[top].end(), greater<int>());
        for(int e: graph[top]) {
            if (!visited[e]) {
                dfs.push(e);
            }
        }
    }
    cout << '\n';

    queue<int> bfs;
    fill(visited.begin(), visited.end(), false);
    bfs.push(v);
    visited[v] = true;
    while(!bfs.empty()) {
        int top = bfs.front(); bfs.pop();
        visited[top] = true;

        cout << top << " ";
        sort(graph[top].begin(), graph[top].end(), less<int>());
        for(int e: graph[top]) {
            if (!visited[e]) {
                visited[e] = true;
                bfs.push(e);
            }
        }
    }
    
}