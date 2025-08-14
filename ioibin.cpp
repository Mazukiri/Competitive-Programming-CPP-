#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second
const int N = 1e6 + 5;
int par[N], sz[N];
int P;

int find(int u) {
    if (u == par[u]) return u;
    return find(par[u]);
}

void join(int u, int v) {
    int a = find(u);
    int b = find(v);

    if (a == b) return;

    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> P;

    for (int i = 1; i<=10000; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    while (P--) {
        int u, v, c; cin >> u >> v >> c;
        if (c == 1) join(u, v);
        else {
            if (find(u) == find(v)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
}