#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
const int N = 3e4 + 5;
const int Q = 2e5 + 5;
const int BLOCK_SIZE = 400;
int cnt[1000005];

//O(Q * sqr(n)) = 
int n, q; 

int ans = 0;
int res[Q];
int A[N];

struct queries {
    int l, r, id;

    bool operator<(const queries &other){
        if (l / BLOCK_SIZE == other.l / BLOCK_SIZE) return r < other.r;
        return l /BLOCK_SIZE < other.l / BLOCK_SIZE;
    }
}; 

queries qr[Q];

void update(int val, int sign) {
    if (sign == 1) ans += (cnt[val]++ == 0);
    if (sign == -1) ans -= (--cnt[val] == 0);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    cin >> q;

    for (int i = 1; i <= q; i++) {
        cin >> qr[i].l >> qr[i].r;
        qr[i].id = i;
    }

    sort(qr + 1, qr + 1 + q);


    int u = 1, v = 0;
    for (int i = 1; i <= q; i++) {
        while (u > qr[i].l) update(A[--u], 1);
        while (v < qr[i].r) update(A[++v], 1);
        while (u < qr[i].l) update(A[u++], -1);
        while (v > qr[i].r) update(A[v--], -1);
        res[qr[i].id] = ans;
    }

    for (int i = 1; i <= q; i++) cout << res[i] << '\n';
    
}