#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m;
vector<int> adj[N];
bool vis[N];

void dfs(int u){
    if (vis[u]) return;
    
    vis[u] = true;

    for (int x: adj[u]){

        if (!vis[x]) dfs(x);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 1; i<=m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    int ans = 0;

    for (int i = 1; i<=n; i++){
        if (!vis[i]) {
            dfs(i);
            ans++;
        }
    }

    cout << ans;
}