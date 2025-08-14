#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
vector<int> adj[N];
bool vis[N];

void dfs(int u){

    vis[u] = true;
 
    for (int x : adj[u]){

        if (!vis[x]) dfs(x);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n, m; cin >> n >> m;

    for (int i = 1; i<=m; i++){

        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i<=n; i++){
        vis[i] = 0;
    }

    int ans = 0;

    for (int i = 1; i<=n; i++){
        if (!vis[i]){
            dfs(i);
            ans++;
        }
    }

    cout << ans;
}