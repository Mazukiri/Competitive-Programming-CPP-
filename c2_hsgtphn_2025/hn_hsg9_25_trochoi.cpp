#include <bits/stdc++.h>                                                                                                                                                                                      //logkit
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second

const int N = 1505;
int n, q;
int a[N][N];
II pos[N * N];
int tmp[N];

int calc(int x, int y) {
    return min(abs(x - y), n - abs(x - y));
}

void updateRow(int u, int step) {
    for (int i = 1; i <= n; ++i) tmp[i] = a[u][i];

    for (int i = 1; i <= n; ++i) a[u][(i + step + n - 1) % n + 1] = tmp[i];

    for (int i = 1; i <= n; ++i) pos[a[u][i]] = II(u, i);
}

void updateCol(int u, int step) {
    for (int i = 1; i <= n; ++i) tmp[i] = a[i][u];

    for (int i = 1; i <= n; ++i) a[(i + step + n - 1) % n + 1][u] = tmp[i];

    for (int i = 1; i <= n; ++i) pos[a[i][u]] = II(i, u);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }
    if (fopen("trochoi.inp", "r")) {
        freopen("trochoi.inp", "r", stdin);
        freopen("trochoi.out", "w", stdout);
    }

    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            int val = (i - 1) * n + j;
            a[i][j] = val;
            pos[val] = II(i, j);
        }
    
    while (q--) {
        int p, x, y; cin >> p >> x >> y;

        int u = pos[p].fi, v = pos[p].se;

        cout << calc(x, u) + calc(y, v) << '\n';

        updateRow(u, y - v); // đẩy hàng u từ cột v tới cột y

        updateCol(y, x - u); // đẩy hàng u từ cột v tới cột y
    }
    return 0;
}
//Long
// đẩy cột y từ hàng x tới hàng u