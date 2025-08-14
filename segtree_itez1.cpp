#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, m, q;
int segTree[4*N];
const int INF = 1e9 + 6;

void update(int pos, int value, int id = 1, int l = 1, int r = n){
    if (l == r) {
        segTree[id] = value;
        return;
    }

    int mid = l + r >> 1;

    if (pos <= mid) {
        update(pos, value, id *2, l, mid);
    }

    else {
        update(pos, value, id *2 + 1, mid + 1, r);
    }

    //push-up
    segTree[id] = segTree[id * 2] + segTree[id * 2 + 1];
}

int get(int u, int v, int id = 1, int l = 1, int r = n) {
    
    if (l >= u && r <= v) {
        return segTree[id];
    }

    if (l > v || r < u ) {
        return 0;
    }

    int mid = l + r >> 1;

    return get(u, v, id * 2, l, mid) + get(u, v, id * 2 + 1, mid + 1, r);

}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> q;

    for (int i = 1; i<=n; i++) {
        //int x; cin >> x;
        update(i, 0);
    }

    

    while (q--) {
        int type, x, y; cin >>  type >> x >> y;
        if (type == 1) {
            update(x, y);
        }

        else {
            cout << get(x, y) << '\n';
        }
    }
 
    
}