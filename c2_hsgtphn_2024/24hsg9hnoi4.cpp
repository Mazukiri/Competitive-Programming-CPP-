#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1005;
int n, m, q, K;
vector<vector<int>> modOfK(N * N);;
int grid[N][N];
int dx[3] = {1, 1, 0}, dy[3] = {0, 1, 1};

bool vis[N][N];


void traverse(int x, int y) {

    if (x < 0 || x > n || y < 0 || y > m) return;

    modOfK[grid[x][y] % K].push_back(1);
    vis[x][y] = true;

    for (int i = 0; i < 3; i++) {
        int u = x + dx[i];
        int v = y + dy[i];
        traverse(u, v);
        //if (!vis[u][v]) traverse(u, v);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m >> q >> K;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    traverse(1, 1);


    for (int i = 1; i<= q; i++) {
        int x; cin >> x;
        cout << modOfK[x].size() << '\n';
    }
}