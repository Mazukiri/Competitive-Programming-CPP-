#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1505;
char grid[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
bool vis[N][N];
int n, m;
int ans = 0;

bool isDecimal(char x){
    return x == '1';
}

bool isBinary(int x){
    return x == '0';
}

bool isInside(int x, int y){

    return 1<=x && x<=n && 1<=y && y<=m;
}

void DFS(int x, int y, int targetX, int targetY){

    vis[x][y] = true;

    if ((x == targetX) && (y == targetY) && isBinary(grid[x][y])) {
        ans++;
        return;
    }

    for (int i = 0; i<4; i++){
        int u = x + dx[i];
        int v = y + dy[i];

        if (isInside(u, v) && !vis[u][v] && isBinary(grid[u][v])) DFS(u, v, targetX, targetY); 
    }
}

void DFS1(int x, int y, int targetX, int targetY){

    vis[x][y] = true;

    if ((x == targetX) && (y == targetY) && isDecimal(grid[x][y])) {
        ans++;
        return;
    }

    for (int i = 0; i<4; i++){
        int u = x + dx[i];
        int v = y + dy[i];

        if (isInside(u, v) && !vis[u][v] && isDecimal(grid[u][v])) DFS1(u, v, targetX, targetY); 
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 1; i<=n; i++){
        string s; cin >> s;
        for (int j = 1; j<=m; j++) {
            grid[i][j] = s[j-1];
        }
    }

    int t; cin >> t;
    while (t--){

        memset(vis, false, sizeof vis);
        ans = 0;

        int startX, startY, endX, endY; 
        cin >> startX >> endX >> startY >> endY;

        memset(vis, false, sizeof vis);
        DFS(startX, endX, startY, endY);

        if (ans > 0) {
            cout << "binary" << '\n';
            continue;
        }

        memset(vis, false, sizeof vis);
        DFS1(startX, endX, startY, endY);

        if (ans > 0){
            cout << "decimal" << '\n';
            continue;
        }

        cout << "neither" << '\n';

    }
}