#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10;
vector<int> adj[N];
bool vis[N];

void DFS(int s){
    //start/source
    vis[s] = true;

    for (int u : adj[s]){

        if (!vis[u]) DFS(u);
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

    cout << "Thu tu di chuyen: ";

    DFS(1);
}