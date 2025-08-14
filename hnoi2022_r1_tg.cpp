#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e3 + 5;
const int INF = 1e9 + 7;
int n, m, k;
int par[N], sz[N];
int fw[N][N];
int center[505];
struct Edge{
    int u, v, c;

    Edge(int newU, int newV, int newC) {
        u = newU;
        v = newV;
        c = newC;
    }

    bool operator<(const Edge& others){
        return c < others.c;
    }
};

vector<Edge> edges;

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int u) {
    if (par[u] != u) par[u] = find(par[u]);
    return par[u];
}

void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
}

void merge(int u, int v) {

    if (sz[u] < sz[v]) swap(u, v);

    sz[u] += sz[v];

    par[v] = u;
}

void sub2() {
    
    //Khoi tao do dai
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) {
            fw[i][j] = INF;
            if (i == j) fw[i][j] = 0;
        }
    }

    for (int i = 0; i < edges.size(); i++) {
        fw[edges[i].u][edges[i].v] = edges[i].c;
        fw[edges[i].v][edges[i].u] = edges[i].c;
    }

    //Floyd - Warshall
        for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) {
            for (int k = 1; k <=n; k++) {
                fw[j][k] = min(fw[j][k], fw[j][i] + fw[i][k]);
            }
        }
    }

    //
    int full = (1 << k);
    int dp[full][n + 5];

        for (int mask = 0; mask < full; ++mask)
            fill(dp[mask], dp[mask] + n + 1, INF);

        // Base case: từng đỉnh
        for (int i = 0; i < k; ++i)
            for (int v = 1; v <= n; ++v)
                dp[1 << i][v] = fw[center[i]][v];

    //For qua tất cả các mask có thể
    for (int mask = 1; mask < full; mask++){
        //For subset
        for (int sub = mask & (mask - 1); sub; sub = (sub - 1) & mask) {
            //generate other from subset
            int other = mask ^ sub;
            //Cap nhat ans
            for (int v = 1; v <=n; v++) dp[mask][v] = min(dp[mask][v], dp[sub][v] + dp[other][v]);
        }

        //Kiem tra xem lieu co thuc su toi uu chua
        for (int u = 1; u<=n; u++) {
            for (int v = 1; v <= n; v++) {
                dp[mask][u] = min(dp[mask][u], dp[mask][v] + fw[u][v]);
            }
        }
        
        // int ans = *min_element(dp[full - 1] + 1, dp[full - 1] + n + 1);
    }

    int ans = INF;

    for (int i = 1; i<=n; i++) ans = min(ans, dp[full - 1][i]);

    cout << ans;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("TG.inp", "r")) {
        freopen("TG.inp", "r", stdin);
        freopen("TG.out", "w", stdout);
    }

    cin >> n >> m >> k;

    for (int i = 0; i<k; i++) {
        int x; cin >> x;
        center[i] = x;
    }


    //Enter edges
    for (int i = 1; i<=m; i++) {
        
        int u, v, c; cin >> u >> v >> c;
        
        edges.push_back(Edge(u, v, c));
    }

    sort(edges.begin(), edges.end());

    //Init par for dsu
    init(n);

    int cost = 0;

    //Case 1: k = n: DSU 
    if (k == n) {
        
        for (int i = 0; i<edges.size(); i++) {
            if (find(edges[i].u) != find(edges[i].v)) {
                join(edges[i].u, edges[i].v);
                cost += edges[i].c;
            }
        }

        cout << cost;
    }

    else sub2();
}