#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second

template<class X, class Y> bool mini(X& x, const Y y) {
    if (x > y) return x = y, 1;
    return 0;
}

const long long N = 1e6 + 5, MOD = 1e9 + 7;
int f[N], dist[20][20];
vector<II> adj[N];
long long dp[1 << 20][20];
int NUM[N];
int n, m, numsbank; 

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

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    memset(dp, 0x3f, sizeof(dp));
    memset(NUM, -1, sizeof(NUM));

    cin >> n >> m >> numsbank;
    vector<int> bank;

    for (int i = 0; i<numsbank; i++) {
        int bankNum; cin >> bankNum;
        bank.push_back(bankNum);
        NUM[bankNum] = i;
    }

    for (int i = 0; i<m; i++) {
        int u, v, d; cin >> u >> v >> d;
        adj[u].push_back({d, v});
        adj[v].push_back({d, u});
    }

    

    //Gan do dai
    for (int i = 0; i<numsbank; i++){
        
        dijkstra(bank[i]);
        for (int j = 0; j<numsbank; j++){
            dist[i][j] = f[bank[j]];
            // cout << i << " " << j << " " << dist[i][j] << '\n';
        }
    }
    
    for (int i= 0; i<numsbank; i++) dp[1 << i][i] = 0;

    long long M = (1 << numsbank);

    for (int mask = 0; mask<M; mask++){
        
        for (int i = 0; i<numsbank; i++)
        if (mask >> i & 1) {

            for (int j = 0; j<numsbank; j++){

                    if (!(mask >> j & 1)){

                        int newMask = (mask | (1 << j));
                        (dp[newMask][j] = min(dp[newMask][j] , dp[mask][i] + dist[i][j]));
                    }
            }
        }
    }

    long long ans = 1e18;

    for (int i = 0; i<numsbank; i++){
        
        ans = min(ans, dp[M-1][i]);

    }

    cout << ans;



    
}