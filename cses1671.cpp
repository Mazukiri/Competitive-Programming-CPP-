#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
#define II pair<int,int>
#define fi first
#define se second
vector<II> adj[N];
int n, m;

int dist[N];
template<class X, class Y> bool mini(X& x, const Y y) {
    if (x > y) return x = y, 1;
    return 0;
}

void dijkstra(int node) {
    memset(dist, 0x3f, sizeof dist);
    priority_queue<II, vector<II>, greater<II>> pq;
    dist[node] = 0;
    pq.push({dist[node], node});

    while (!pq.empty()) {
        II u = pq.top();
        pq.pop();

        //check out-dated note
        if (u.fi != dist[u.se]) continue;

         for (II v : adj[u.se]) {
            if (mini(dist[v.se], dist[u.se] + v.fi)) {
                pq.push({dist[v.se], v.se});
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
    }

    
    dijkstra(1);

    for (int i = 1; i<=n; i++) cout << dist[i] << " ";
}