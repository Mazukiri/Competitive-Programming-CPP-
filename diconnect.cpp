#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5; // Adjust size based on constraints
int t, n, m;
vector<int> adj[N], rev_adj[N];
bool vis[N];

void dfs(int u, vector<int> adj_list[]) {
    vis[u] = true;
    for (int v : adj_list[u]) {
        if (!vis[v]) dfs(v, adj_list);
    }
}

bool is_strongly_connected() {
    // Step 1: Check if all nodes are reachable from node 1
    memset(vis, 0, sizeof(vis));
    dfs(1, adj);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) return false; // Not all nodes are reachable
    }

    // Step 2: Check reachability in the transposed graph
    memset(vis, 0, sizeof(vis));
    dfs(1, rev_adj);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) return false; // Not all nodes are reachable in the reverse graph
    }

    return true; // Graph is strongly connected
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> t;
    while (t--) {
        cin >> n >> m;

        // Clear previous test case data
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            rev_adj[i].clear();
        }

        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            rev_adj[v].push_back(u); // Reverse edge for transposed graph
        }

        if (is_strongly_connected()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
