#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int par[N], sz[N];
int n, m, k, q;

int find(int u) {
    return (u == par[u]) ? u : (par[u] = find(par[u])); 
}

void join(int u, int v) {
    int a = find(u);
    int b = find(v);

    if (a == b) continue;

    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m >> k;

    for (int i = 1; i<=m; i++) {
        int u, v;
        join(u, v);
    }

    for (int i = 1; i<=n; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    cin >> q;

    while (q--) {
        char c; cin >> c;

        if (c == '?') {
            int u; cin >> u;
            cout << sz[find(u)] << '\n';
        }

        else {
            int u, v; 
            join(u, v);
        }
    }
}