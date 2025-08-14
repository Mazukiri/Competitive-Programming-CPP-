#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, k, components;
int par[N], sz[N];

struct edge{
    int u, v, c;

    edge(int u, int v, int c) : u(u), v(v), c(c){}

    bool operator<(edge &other) {
        return c < other.c;
    }
};

int find(int u) {
    if (u == par[u]) return u;
    return find(par[u]);
    // return par[u] = find(par[u]);
    
    // while (u != par[u]) {
    //     u = par[u];
    // }

    // return u;
}

void join(int u, int v) {
    int a = find(u);
    int b = find(v);
    
    if (a == b) return;

    components--;

    if (sz[a] < sz[b]) swap(a, b);

    sz[a] += sz[b];
    par[b] = a;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m >> k;

    components = n;

    for (int i = 1; i<=n; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    for (int i = 1; i<=m; i++) {
        int u, v; cin >> u >> v;
        join(u, v);
    }

    cout << components << " ";

    for (int i = 1; i<=k; i++) {
        int t, u, v; cin >> t >> u >> v;
        if (t == 1) {
            join(u, v);
            cout << components << " ";
        }

        else {
            if (sz[u] == 1 || sz[v] == 1) {
                components++;
                
                if (sz[u] == 1) par[u] = u;
                else par[v] = v;

                cout << components << " ";
            }
        }
    }
}

    

    
