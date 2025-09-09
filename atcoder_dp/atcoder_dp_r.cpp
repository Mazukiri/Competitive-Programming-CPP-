#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
int f[N];

template<class X, class Y> bool mini(X& x, const Y y) {
    if (x > y) return x = y, 1;
    return 0;
}

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