#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

int f[N];
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

    
}