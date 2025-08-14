#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second
const int N = 1e5 + 5;
int n, m;
vector<II> adj[N];

int f[N];

template<class X, class Y> bool mini(X& x, const Y y) {
    if (x > y) return x = y, 1;
    return 0;
}

void dijkstra(int node) {
    memset(f, 0x3f3f3f3f3f, sizeof f);
    priority_queue<II, vector<II>, greater<II>> q;
    q.push({0, node});
    f[node] = 0;
    while (!q.empty()) {
        II u = q.top(); q.pop();
        if (u.fi != f[u.se])
            continue;
        
        for (II v: adj[u.se]) {
                if (mini(f[v.se], max(v.fi, f[u.se]))) {
                    q.push({f[v.se], v.se});
                }
                
            }
            
        }
    }


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 1; i<=m; i++) {
        int u, v, c; cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }

    dijkstra(1);

    cout << f[n];
} 