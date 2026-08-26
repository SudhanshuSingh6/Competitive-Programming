#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
const vector<tuple<int, int, char>> dirs = 
{{-1, 0,'U'},{1, 0,'D'},{0, -1,'L'},{0, 1,'R'}};

bool valid(int i, int j){
    if (i < n && i >= 0 && j < m && j >= 0 && grid[i][j] != '#')
        return true;
    return false;
}

bool dfs(int i,int j,string &directions){
    if(grid[i][j] == 'B')
        return true;
    grid[i][j]='#';
    for(auto[dx,dy,c]:dirs){
        int x = dx+i;
        int y = dy+j;
        if(valid(x,y)){
            directions.push_back(c);
            if (dfs(x, y, directions))
                return true;
            directions.pop_back();
        }
    }
    return false;
}
int main(){
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    string directions;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 'A'){
                //bfs(i,j);
                dfs(i,j,directions);
                break;
            }
        }
    }
    if(directions.size() == 0)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        cout << directions.size() << endl;
        cout << directions << endl;
    }
}