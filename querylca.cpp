#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10;  // You may adjust based on problem constraints
const int K = log2(N) + 1;
int par[N][K];
int n, q;
int depth[N];
vector<int> adj[N];

void dfs(int u) {
    for (int v : adj[u]) {
        if (par[u][0] != v) {
            depth[v] = depth[u] + 1;
            par[v][0] = u;
            dfs(v);
        }
    }
}

void preprocess() {
    for (int k = 1; k <= K; k++) {
        for (int u = 1; u <= n; u++) {
            int x = par[u][k - 1];
            if (x != 0) par[u][k] = par[x][k - 1];
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    // Bring u and v to the same depth
    for (int k = K; k >= 0; k--) {
        if ((1LL << k) <= depth[u] - depth[v]) u = par[u][k];
    }

    if (u == v) return u;

    for (int k = K; k >= 0; k--) {
        if (par[u][k] != 0 && par[u][k] != par[v][k]) {
            u = par[u][k];
            v = par[v][k];
        }
    }

    return par[u][0];
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;
    
    for (int i = 1; i <= n - 1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Initialize parent for the root node
    par[1][0] = 0;
    depth[1] = -1;


    dfs(1);
    preprocess();

    cin >> q;

    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;

        int final_lca = l;
        for (int u = l + 1; u <= r; u++) {
            final_lca = lca(final_lca, u);
        }

        cout << final_lca << '\n';
    }
}
