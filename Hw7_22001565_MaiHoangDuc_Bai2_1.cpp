/*
1. Quy Hoạch Động đếm số đường đi ngắn nhất:
Đề bài: https://vjudge.net/problem/Gym-406204J
Tài liệu tham khảo: https://wiki.vnoi.info/vnoi-magazine/2023/shortest-path-dag
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second
int n, m;
const int N = 1e5 + 5;
int f[N], ways[N];
vector<II> adj[N];

void Djikstra(int node) {
    memset(f, 0x3f3f3f3f, sizeof f);
    memset(ways, 0, sizeof ways);
    f[node] = 0;
    ways[node] = 1;
    priority_queue<II, vector<II>, greater<II>> q;
    q.push({0, node});

    while (!q.empty()) {
        II u = q.top();
        q.pop();
        
        if (u.fi != f[u.se]) continue;

        for (II v: adj[u.se]) {

            if (f[v.se] == f[u.se] + v.fi) {
                ways[v.se] += ways[u.se];
            }

            if (f[v.se] > f[u.se] + v.fi) {
                ways[v.se] = ways[u.se];
                f[v.se] = f[u.se] + v.fi;
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

    Djikstra(1);

    for (int i = 1; i<=n; i++) {
        cout << f[i] << " " << ways[i] << '\n';
    }
} 