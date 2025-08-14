#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int par[N], sz[N];
int ans, n, m, components;


int find(int u) {
    while (u != par[u]) {
        u  = par[u];
    }
    
    return u;
}

void join(int u, int v) {

    int a = find(u);
    int b = find(v);

    if (a == b) return;
    
    components--;
    
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    
    ans = max(ans, sz[a]);
  
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    ans = 0;    

    cin >> n >> m;

    components = n;

    //init
    for (int i = 1; i <=n; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    
    for (int i = 1; i<=m; i++) {
        int u, v; cin >> u >> v;
        join(u, v);
        cout << components << " " << ans << '\n';
    }

    
}