#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second
const int N = 505;
vector<II> adj[N];
int n, m, q;
int D[N][N];

void floydWarshall() {
    for (int k = 1; k <= n; k++) {  
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (D[u][k] != LLONG_MAX && D[k][v] != LLONG_MAX) {  
                    D[u][v] = min(D[u][v], D[u][k] + D[k][v]);
                }
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

    cin >> n >> m >> q;

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) D[i][j] = 0;  
            else D[i][j] = LLONG_MAX;
        }
    }

    for (int i = 1; i <= m; i++) {
        int u, v, c; cin >> u >> v >> c;
        D[u][v] = min(D[u][v], c);  
        D[v][u] = min(D[v][u], c);
    }

    floydWarshall();

    while (q--) {
        int a, b; cin >> a >> b;
        cout << (D[a][b] == LLONG_MAX ? -1 : D[a][b]) << '\n';
    }
}
