#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int lazy[4 * N], seg[4 * N], a[N];
int n, q; 

void pushdown(int id, int l, int r){
    //push-down lazy xuống
    if (lazy[id] == 0) return;

    int mid = l + r >> 1;

    seg[id << 1] += (lazy[id] * (mid - l + 1));
    lazy[id << 1] += lazy[id];

    seg[id << 1 | 1] += (lazy[id] * (r - mid));
    lazy[id << 1 | 1] += lazy[id];

    lazy[id] = 0;
}

void update(int u, int v, int val, int id = 1, int l = 1, int r = n){

    if (u > r || l > v) return;
    
    if (u <= l && r <= v) {
        lazy[id] += val;
        seg[id] += val * (r - l + 1);
        return;
    } 

    pushdown(id, l, r);

    int mid = l + r >> 1;

    update(u, v, val, id << 1, l, mid);
    update(u, v, val, id << 1 | 1, mid + 1, r);

    seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

int get(int u, int v, int id = 1, int l = 1, int r = n){

    if (u > r || l > v) return 0;

    if (u <= l && r <= v) return seg[id];
    
    pushdown(id, l, r);
    int mid = l + r >> 1;
    
    return get(u, v, id << 1, l, mid)
        + get(u, v, id << 1 | 1, mid + 1, r);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> q;

    for (int i = 1; i<=n; i++){
        cin >> a[i];
        update(i, i, a[i]);
    }

    while (q--){
        int typ; cin >> typ;

        if (typ == 1){
            int l, r, val; cin >> l >> r >> val;
            update(l, r, val);
        }

        else {
            int k; cin >> k;
            cout << get(k , k) << '\n';
        }
    }
}