#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;
int n, m;
char grid[N][N];
bool vis[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isInside(int x, int y){
    return 0<=x  && x<n && 0<=y && y<m;
}

void DFS(int u, int v){
    
    if (vis[u][v]) return;
    vis[u][v] = true;

    for (int i = 0; i<4; i++){
        int u1 = u + dx[i];
        int v1 = v + dy[i];
        if (isInside(u1, v1) && !vis[u1][v1]) DFS(u1, v1);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++) cin >> grid[i][j];
    }    

    int ans = 0;

    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++) {
            if (!vis[i][j] && grid[i][j] == '1'){
                ans++;
                DFS(i, j);
            }
        }
    }

    cout << ans;




}