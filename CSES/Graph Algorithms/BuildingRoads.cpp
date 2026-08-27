#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int i, vector<bool>& vis){
    vis[i] = true;
    for (int u : adj[i]){
        if (!vis[u])
            dfs(adj, u, vis);
    }
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n+1);
    vector<pair<int, int>> ans;
    dfs(adj,1,vis);
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            dfs(adj, i, vis);
            ans.push_back({1, i});
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}