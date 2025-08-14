#include <bits/stdc++.h>
using namespace std;
#define II pair<int,int>
#define fi first
#define se second
const int N = 1e5 + 5;
const int INF = 1e9;
priority_queue<II, vector<II>, greater<II>> q;
vector<II> adj[N];
int n, m, k;

template<class X, class Y> bool mini(X& x, const Y y) {
    if (x > y) return x = y, 1;
    return 0;
}

int f[N][19];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m >> k;
    
    for (int i = 1; i <= m; i++) {
        int u,v,c; cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }

    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;

    for (int i = 0; i<=k; i++) {

        /* TLE */
        for (int j = 1; j<=n; j++) q.push({f[j][i], j});
        

        while (!q.empty()) {
            II u = q.top(); q.pop();
            if (u.fi != f[u.se][i] || u.fi > f[u.se][i- 1])
                continue;
            
            for (II v: adj[u.se]) {
                if (mini(f[v.se][i], min(f[u.se][i] + v.fi, (i == 0 ? INF : f[u.se][i - 1])))) {
                    q.push({f[v.se][i], v.se});
                }
            }
        }
        
        if (i == k) break;

        
        /* TLE
        for (int u = 1; u <= n; u++) {
            for (II v : adj[u]) {
                //Su dung ve giam gia
                mini(f[v.se][i + 1], f[u][i]);  
            }
        }
        */
    }

    //Nút (1, 0) bắt đẩu, các nút còn lại như nhau sau khi đẩy vào pq

    /*
    for (int i = 1; i<=n; i++) {
        for (int j = 0; j<=k; j++) 
            cout << i << " " << j << " " << f[i][j] << '\n';
        cout << '\n';
    }
    */

    for (int i = 1; i<=n; i++) {
        int ans = f[i][0];
         
        for (int j = 1; j<=k; j++) {
            ans = min(ans, f[i][j]);    
        }

        cout << ans << " ";
    }


}