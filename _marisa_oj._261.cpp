#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
int n, q;
const int N = 1e5 + 5;
const int BLOCKSIZE = 450;
int A[N], res[N], cnt[N], cnt2[N];

void update(int val, int sign) {
    if (sign == 1) {
        cnt2[cnt[val]]--;
        cnt[val]++;
        cnt2[cnt[val]]++;
    }

    else {
        cnt2[cnt[val]]--;
        cnt[val]--;
        cnt2[cnt[val]]++;
    }
}

struct queries {
    int l, r, id, x;

    bool operator<(const queries &other) {
        if (l / BLOCKSIZE == other.l / BLOCKSIZE) return r < other.r;
        return l / BLOCKSIZE < other.l / BLOCKSIZE;
    }
} qr[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= 100000; i++) cnt2[cnt[i]]++;

    for (int i = 1; i <= q; i++) {
        cin >>  qr[i].l >> qr[i].r >> qr[i].x;
        qr[i].id = i;
    }

    sort(qr + 1, qr + 1 + q);

    int u = 1, v = 0;

    for (int i = 1; i <= n; i++) {
        while (u > qr[i].l) update(A[--u], 1);
        while (v < qr[i].r) update(A[++v], 1);
        while (u < qr[i].l) update(A[u++], -1);
        while (v > qr[i].r) update(A[v--], -1);

        res[qr[i].id] = cnt2[qr[i].x];
    }

    for (int i = 1; i <=q; i++) cout << res[i] << '\n';
    
}