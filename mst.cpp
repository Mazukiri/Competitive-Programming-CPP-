#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m;
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

    if (sz[a] < sz[b]) swap(a, b);

    sz[a] += sz[b];
    par[b] = a;
}

vector<edge> edges;


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 1; i<=m; i++) {
        int u, v, c; cin >> u >> v >> c;
        edges.push_back(edge(u, v, c));
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i<=n; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    int cost = 0;

    for (int i = 0; i<edges.size(); i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            join(edges[i].u, edges[i].v);
            cost += edges[i].c;
        }
    }

    cout << cost;

    
}