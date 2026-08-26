#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
const vector<pair<int, int>> dirs = {{-1, 0},{1, 0},{0, -1},{0, 1}};

bool valid(int i, int j){
    if (i < n && i >= 0 && j < m && j >= 0 && grid[i][j] == '.')
        return true;
    return false;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    grid[x][y] = '#';
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (auto [dx, dy] : dirs) {
            int x = i + dx;
            int y = j + dy;
            if (valid(x, y)) {
                grid[x][y] = '#';
                q.push({x, y});
            }
        }
    }
}

void dfs(int i,int j){
    grid[i][j]='#';
    for(auto[dx,dy]:dirs){
        int x = dx+i;
        int y = dy+j;
        if(valid(x,y))
            dfs(x,y);
    }
}
int main(){
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    int rooms = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == '#')
                continue;
            rooms++;
            bfs(i,j);
            //dfs(i,j);
        }
    }
    cout << rooms << endl;
}