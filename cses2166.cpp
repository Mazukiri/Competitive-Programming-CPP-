#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, q;
const int N = 1e6 + 5;
int A[N];
int prefix[N];
const int INF = 1e18;
int seg[N*4], lazy[N*4];
void pushdown(int id) {
    seg[id << 1] += lazy[id]; seg[id << 1 | 1] += lazy[id];
    lazy[id << 1] += lazy[id]; lazy[id << 1 | 1] += lazy[id];
    lazy[id] = 0;
}
void update(int u, int v, int x, int id = 1, int l = 0, int r = n) {
    if (l > r || r < u || v < l) return ;
    if (u <= l && r <= v) {
        seg[id] += x; lazy[id] += x;
        return ;
    }
    pushdown(id);
    int mid = l + r >> 1;
    update(u, v, x, id << 1, l, mid);
    update(u, v, x, id << 1 | 1, mid + 1, r);
    seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}
int get(int u, int v, int id = 1, int l = 0, int r = n) {
    if (l > r || r < u || v < l) return -INF;
    if (u <= l && r <= v) return seg[id];
    pushdown(id);
    int mid = l + r >> 1;
    return max(
        get(u, v, id << 1, l, mid),
        get(u, v, id << 1 | 1, mid + 1, r)
    );
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> q;

    for (int i = 1; i<=n; i++) {
        cin >> A[i];
        prefix[i] = prefix[i - 1] + A[i];
        update(i, i, prefix[i]);
    }
    
    for (int i = 1; i<=q; i++) {
        int x, y, typ;
        cin >> typ >> x >> y;
        
        if (typ == 1) {
            update(x, n, - A[x] + y);
            A[x] = y;
        }

        else {
            //Cẩn x - 1 = 0 ==> Không phải là một ptu quản lý trong segment tree
            //cần đẩy prefix[0] vào trong cây để có thể thỏa mãn tính chất.
            cout << max(0LL, get(x , y) - get(x - 1, x - 1)) << '\n';
        }

        // for (int j = 1; j<=n; j++) cout << get(j, j) << " ";
        // cout << '\n';
    }
    
}