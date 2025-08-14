#include <bits/stdc++.h>
using namespace std;
#define II pair<int,int>
#define fi first
#define se second
const int N = 1505;
int unfrozen_days[N][N];
char SwanLake[N][N];
vector<II> Swans;
queue<II> q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
bool vis[N][N];
int n, m;

bool isInside(int x, int y){

    return 1<=x && x<=n && 1<=y && y<=m;
}

bool isIce(int x, int y){
    return (SwanLake[x][y] == 'X');
}

void DFS(int x, int y, int limit){

    vis[x][y] = true;

    for (int i = 0; i<4; i++){
        int u = x + dx[i];
        int v = y + dy[i];

        if (isInside(u, v) && !vis[u][v] && unfrozen_days[u][v] <= limit) DFS(u, v, limit); 
    }
}

bool check(int mid){

    memset(vis, false, sizeof vis);

    DFS(Swans[0].fi, Swans[0].se, mid);

    return vis[Swans[1].fi][Swans[1].se];
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    memset(unfrozen_days, -1, sizeof unfrozen_days);

    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++) {
            cin >> SwanLake[i][j];

            if (SwanLake[i][j] == 'L') Swans.push_back(II(i, j));

            if (SwanLake[i][j] != 'X') {
                unfrozen_days[i][j] = 0;
                q.push(II(i, j));
            }
        }
    }
    
    //unfronzen_days: so ngay tan bang
    //q: cac o la nuoc

    int l = 1, r;

    while (!q.empty()){
        II u = q.front();
        q.pop();

        for (int i = 0; i<4; i++){
            
            int x = u.fi + dx[i];
            int y = u.se + dy[i];

            if (isInside(x, y) && isIce(x, y) && unfrozen_days[x][y] == -1) {
                q.push({x, y}); 
                r = unfrozen_days[x][y] = unfrozen_days[u.fi][u.se] + 1; 
            }
        }
    }

    // for (int i = 1; i<=n; i++){
    //     for (int j = 1; j<=m; j++) {
    //         cout << unfrozen_days[i][j] << " ";
    //     }

    //     cout << '\n';
    // }

    int ans;

    while (l<=r){

        int mid = (l+r)/2;

        if (check(mid)){
            ans = mid;
            r = mid - 1;
        }

        else l = mid + 1;
    }

    cout << ans;

}