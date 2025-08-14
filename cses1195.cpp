/*
    Đề bài: https://cses.fi/problemset/task/1195
    Lời giải: https://hackmd.io/@merciless-lassie/rkCfQ1UqJl
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second
const int N = 1e6 + 5;
const int MAX = 1e18;
int cost[2][N];
vector<II> adj[N];
int n, m;

template<class X, class Y> bool mini(X& x, const Y y) {
    if (x > y) return x = y, 1;
    return 0;
}

void dijkstra(int node) {
    for (int i = 1; i <= n; i++) cost[0][i] = MAX;
    priority_queue<II, vector<II>, greater<II>> pq;
    pq.push({0, node});
    cost[0][node] = 0;

    while (!pq.empty()) {
        II u = pq.top();
        pq.pop();

        if (u.fi != cost[0][u.se]) continue;

        for (II v : adj[u.se]) {
            if (mini(cost[0][v.se], cost[0][u.se] + v.fi)) {
                pq.push({cost[0][v.se], v.se});
            }
        }
    }
}

void dijkstra2(int node) {
    for (int i = 1; i <= n; i++) cost[1][i] = MAX;
    priority_queue<II, vector<II>, greater<II>> pq;
    pq.push({0, node});
    cost[1][node] = 0;

    while (!pq.empty()) {
        II u = pq.top();
        pq.pop();

        if (u.fi != cost[1][u.se]) continue;

        for (II v : adj[u.se]) {
        
            

            /*Lỗi chí mạng
            bool flag = false;

            if (mini(cost[1][v.se], cost[0][u.se] + (v.fi / 2)) ||
                mini(cost[1][v.se], cost[1][u.se] + v.fi)) {
                
                    pq.push({cost[1][v.se], v.se});
            }
            */

            bool flag = false;
 
            if (mini(cost[1][v.se], cost[0][u.se] + (v.fi / 2))) {
                flag = true;
            }
 
            if (mini(cost[1][v.se], cost[1][u.se] + v.fi)) {
                flag = true;
            }
 
            if (flag) pq.push({cost[1][v.se], v.se});
            
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
    }

    dijkstra(1);
    
    // for (int i = 1; i<=n; i++) cout << cost[0][i] << " ";
    cout << '\n';

    dijkstra2(1);

    // for (int i = 1; i<=n; i++) cout << cost[1][i] << " ";
    

    cout << cost[1][n];
}
