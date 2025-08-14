#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
const int K = 18;
int n, q;
vector<int> adj[N];
int depth[N];
int par[N][K];

void dfs(int u) {

    for (int v: adj[u]) {
        if (par[u][0] != v) {
            par[v][0] = u;
            depth[v] = depth[u] + 1;
            dfs(v);
        }
    }
}

void preprocess(){

    for (int k = 1; k<K; k++){
        for (int u = 1; u<=n; u++){
            par[u][k] = par[par[u][k-1]][k-1];
        }
    }
}

int lca(int u, int v) {
    
    if (depth[u] < depth[v]) swap(u, v);

    //Balance the depth of node u and node v
    for (int k = K - 1; k>=0; k--){
        if (depth[par[u][k]] >= depth[v]) {
            u = par[u][k];
        }
    }

    if (u == v) return u;

    //Go the child node of LCA(u, v) from u and from v
    for (int k = K - 1; k>=0; k--) {
        if (par[u][k] != par[v][k]) {
            u = par[u][k];
            v = par[v][k];
        }
    }

    return par[u][0];
}

int dist(int u, int v) {

    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> q;

    for (int i = 1; i<n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[0] = -1;

    dfs(1);
    preprocess();

    while (q--) {
        int u, v, camera; cin >> u >> v >> camera;
        // cout << lca(u, v) << '\n';
        if (dist(u, v) != dist(v, camera) + dist(u, camera)) cout << 0 << '\n';
        else cout << 1 << '\n';
    }

    


}