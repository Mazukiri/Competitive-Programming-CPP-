#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int n, m;
const int N = 10;
int ans = 0;
bool vis[N];
vector<int> adj[N];

void dfs(int u){
    if (vis[u]) return;

    for (int v: adj[u]){
        dfs(v);
    }

    vis[u] = 1;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;
    
    for (int i = 1; i<=n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i<=n; i++){
        if (!vis[i]) {
            ans++;
            dfs(i);
        }
    }   

    cout << ans;
}