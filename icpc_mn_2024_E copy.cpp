#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const long long N = 1e6 + 5;
int n, T; 
vector<int> adj[N];
bool vis[N];

bool dfs(int u, int v){
    
    if (u == v) return true;
    
    vis[u] = true;
    
    for (int e : adj[u]) {
        if ((!vis[e]) && (dfs(e, v))) return true;
    }

    return false;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    memset(vis, false, sizeof(vis));

    cin >> n;

    for (int i = 1; i<=n-1; i++){

        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    
    cin >> T;

    for (int i = 1; i<=T; i++){

        
        int u, v; cin >> u >> v; 
        memset(vis, false, sizeof(vis));
        if (dfs(u, v)) cout << "Yes" << '\n'; else cout << "No" << '\n';
        
    }
}    
