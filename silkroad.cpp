#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m;
#define II pair<int,int>
#define fi first
#define se second
// vector<II> adj[N];

struct edges{

    int x;
    int y;
    int c;
};

bool cmp(edges &u, edges &v){
    return u.c < v.c;
}

vector<edges> ed;

int par[N], rak[N];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        rak[i] = 0;
    }
}

int find(int u) {
    if (par[u] != u) par[u] = find(par[u]);
    return par[u];
}

bool join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return 0;
    if (rak[u] == rak[v]) ++rak[u];
    if (rak[u] < rak[v]) par[u] = v;
    else par[v] = u;
    return 1;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 1; i<=m; i++){
        
        int u, v, c; cin >> u >> v >> c;
        ed.push_back({u, v, c});           
    }

    

    sort(ed.begin(), ed.end(), cmp);

    init(n);

    for (auto canh : ed){

        join(canh.x, canh.y);

        if (find(1) == find(n)){
            cout << canh.c;
            return 0;
        }
    }
    
}