#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, s, t; 
vector<int> ans;
bool vis[N];
vector<int> adj[N];
vector<string> path;

void DFS(int u){

    ans.push_back(u);
    vis[u] = true; 
    if (u == t) {
        for (int i = 0; i<ans.size(); i++) 
        if (i != ans.size() - 1) cout << ans[i] << " "; else cout << ans[i];
        exit(0);
    }
        
    for (int v: adj[u]){
        if (!vis[v]) DFS(v);
    }

    ans.pop_back();



}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m >> s >> t;

    for (int i = 1; i<=m; i++){

        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i<=n; i++) sort(adj[i].begin(), adj[i].end());

    DFS(s);
    
}