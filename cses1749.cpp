#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;
int seg[4*N];

void update(int pos, int val, int id = 1, int l = 1, int r = n){

    if (l == r){
        seg[id] = val;
        return;
    }

    int mid = l+ r >> 1;

    if (pos <= mid) update(pos, val, id * 2, l, mid);
    else update(pos, val, id * 2 + 1, mid + 1, r);

    seg[id] = seg[id*2] + seg[id*2 + 1];
}

int get(int u, int v, int id, int l, int r){

    if (u > r || l > v) return 0;
    if (u <= l && r <= v) {
        
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    for (int i = 1; i<=n; i++){
        int x; cin >> x;
        update(i, x);
    }

    for (int i = 1; i<=n; i++){
        int q; cin >> q;

        int ans = bs(q);
        cout << ans << '\n';
    }
}