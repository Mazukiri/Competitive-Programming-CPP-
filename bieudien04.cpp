#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
vector<int> adj[1000005];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n, m; cin >> n >> m;

    for (int i = 1; i<=m; i++){
        
        int u, v; cin >> u >> v;
        if (u == v) continue; //loại khuyên
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u = 1; u<=n; u++) cout << adj[u].size() << " ";

            
        
        
}   
