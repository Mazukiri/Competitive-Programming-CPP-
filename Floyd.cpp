#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair<int, int>
#define fi first
#define se second

const int N = 1005;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

int n, m;
int D[N][N];



signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    memset(D, 0x3f, sizeof D);

    for (int i = 1; i <= n; i++) D[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        D[u][v] = min(D[u][v], c);
    }

    // Floyd-Warshall chuẩn
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (D[i][k] < INF && D[k][j] < INF) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
    }

    // In đường đi từ đỉnh 1 đến các đỉnh khác
    for (int i = 1; i <= n; i++) {
        cout << (D[1][i] == INF ? -1 : D[1][i]) << " ";
    }
}

int f[N];
void dijkstra(int node) {
    memset(f, 0x3f, sizeof f);
    priority_queue<II, vector<II>, greater<II>> q;
    q.push({0, node});
    f[node] = 0;
    while (!q.empty()) {
        II u = q.top(); q.pop();
        if (u.fi != f[u.se])
            continue;
        for (II v: adj[u.se]) {
            if (mini(f[v.se], f[u.se] + v.fi)) {
                q.push({f[v.se], v.se});
            }
        }
    }
}