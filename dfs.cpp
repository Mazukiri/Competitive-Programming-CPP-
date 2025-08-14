#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const long long N = 1e6 + 5;
int n, m; 
vector<int> adj[N];
bool vis[N];

void dfs(int u){
    if (vis[u]) return;
    
    vis[u] = true;
    
    for (int e : adj[u]) {
        if (!vis[e]) dfs(e);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    memset(vis, false, sizeof(vis));

    cin >> n >> m;

    for (int i = 1; i<=m; i++){

        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;

    for (int i = 1; i<=n; i++) {
        if (!vis[i]){
            ans++;
            dfs(i);
        }
    }
    cout << ans;

    

}    
