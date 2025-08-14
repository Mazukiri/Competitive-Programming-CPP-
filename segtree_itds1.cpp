#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 1e9 + 7;
int n, q; 
int A[N];
multiset<int> segTree[4 * N];


void update(int pos, int value, int id = 1, int l = 1, int r = n) {
    
    if (l == r) {
        segTree[id].erase(A[pos]);
        segTree[id].emplace(value);
        return;
    }

    int mid = l + r >> 1;

    if (pos <= mid) {
        update(pos, value, id << 1, l, mid);
    }

    else update(pos, value, id << 1 | 1, mid + 1, r);

    segTree[id] = segTree[id << 1];
    segTree[id].insert(segTree[id << 1 | 1].begin(), segTree[id << 1 | 1].end());
}

int get(int u, int v, int k, int id = 1, int l = 1, int r = n) {
    if (u <= l && r <= v) {
        std::multiset<int>::iterator ans = segTree[id].lower_bound(k);
        if (ans == segTree[id].cend()) return -1;
        return *ans;
    }

    if (u > r || l > v) return INF;

    int mid = l + r >> 1;

    int lf = get(u, v, k, id << 1, l, mid);
    int rt = get(u, v, k, id << 1 | 1, mid + 1, r);

    return min(lf, rt);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> q;

    for (int i = 1; i<=n; i++) {
        int x; cin >> x;
        update(i, x);
        A[i] = x;
    }

    for (int i = 1; i<=q; i++) {
        int typ; cin >> typ;
        if (typ == 1) {
            int pos, val; cin >> pos >> val;
            update(pos, val);
            A[pos] = val;
        }

        else {
            int l, r, k; cin >> l >> r >> k;
            cout << get(l, r, k) << '\n';
        } 
    }



    
}