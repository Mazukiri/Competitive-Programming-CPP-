#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
#define II pair<int,int>
#define fi first
#define se second
int n, m;
vector<int> adj[N];
vector<II> edge_list;
//adj[1] = {2, 5, 6}
//adj[2] = {1, 3, 4}
//adj[3]= ...
// int adjMatrix[N][N];
//int cost[N][N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    //Adjacency matrix
    //Adjacency list
    //Edge list
    cin >> n >> m;

    //Ma tran ke
    // for (int i = 1; i<=m; i++){
    //     int u, v; cin >> u >> v;
    //     adjMatrix[u][v] = 1;
    //     adjMatrix[v][u] = 1;
    // }

    // for (int i = 1; i<=n; i++) {
    //     cout << "Vertices " << i << " adjacent with vertices: ";
    //     for (int j = 1; j<=n; j++) if (adjMatrix[i][j]) cout << j << " ";
    //     cout << '\n';
    // }

    // for (int i = 1; i<=n; i++){
    //     for (int j = 1; j<=n; j++) cout << adjMatrix[i][j] << " ";
    //     cout << '\n';
    // }

    //Danh sach ke
    // for (int i = 1; i<=m; i++){
    //     int u, v; cin >> u >> v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }

    // for (int i = 1; i<=n; i++) {
    //     cout << "Adjacent vertices with vertices " << i << " are: ";
    //     // for (int x = 0; x<adj[i].size(); x++) cout << adj[i][x] << " ";
    //     for (int x : adj[i]) cout << x << " ";
    //     cout << '\n';
    // }

    //Danh sach canh
    for (int i = 1; i<=m; i++){
        int u, v; cin >> u >> v;
        edge_list.push_back({u, v});
        // edge_list.push_back(II (u, v));
    }
    
}


