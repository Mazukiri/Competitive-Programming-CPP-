#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m;
int par[N], sz[N];

struct edge {
    int u, v, c;

    edge(int u, int v, int c) : u(u), v(v), c(c){}

    bool operator<(edge &other) {
        return c < other.c;
    }
};

vector<edge> edges;

int find(int u) {
    if (u == par[u]) return u;
    return find(par[u]);
}

void join(int u, int v) {

    //if (a == b) return;
    if (sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    int total_cost = 0;

    for (int i = 1; i<=m; i++) {
        int u, v, c; cin >> u >> v >> c;
        edges.push_back(edge(u, v, c));
    }

    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i<edges.size(); i++) {
        
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if (a != b) {
            join(a, b);
            total_cost += edges[i].c;
        }
    }

    for (int i = 1; i<=n-1; i++) {
        if (find(i) != find(i + 1)) return cout << "IMPOSSIBLE", 0;
    }
 
    cout << total_cost;





    

    
}