#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int n, q;
const int N = 1e6 + 5;
int seg[4 * N];

void update(int pos, int val, int id = 1, int l = 1, int r = n){

    if (l == r){
        seg[id] = val;
        return;
    }

    int mid = (l+r)/2;

    //push_down
    if (pos <= mid) update(pos, val, id*2, l, mid);
    else update(pos, val, id*2 + 1, mid + 1, r);

    //push_up
    seg[id] = (seg[id*2] ^ seg[id*2 + 1]);
} 

int get(int u, int v, int id = 1, int l = 1, int r = n){

    if (u <= l && r <= v) return seg[id];
    if (u > r || l > v) return 0;

    int mid = (l+r)/2;

    return (
        get(u, v, id*2, l, mid) 
       ^ get(u, v, id*2 + 1, mid + 1, r)
    );
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> q;

    memset(seg, 0, sizeof seg);

    for (int i = 1; i<=n; i++) {
        int x; cin >> x; 
        update(i, x);
    }

    while (q--){
        
            int u, v; cin >> u >> v;
            cout << get(u, v) << '\n';
        }
}