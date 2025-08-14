#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
int n, q;
const int BLOCKSIZE = 450;
const int N = 2e5 + 5;
long long A[N], BLOCK[BLOCKSIZE];

void update(int key, long long value) {

    BLOCK[key/BLOCKSIZE] -= A[key];
    A[key] = value;
    BLOCK[key/BLOCKSIZE] += A[key];
}

long long get(int l, int r) {
    
    long long res = 0;

    if (l/BLOCKSIZE == r/BLOCKSIZE) {
        for (int i = l; i <= r; i++) {
            res += A[i];
        }
        return res;
    }

    else {

        for (int i = l; i < (l/BLOCKSIZE + 1) * BLOCKSIZE; i++) {
            res += A[i];
        }

        for (int i = (l/BLOCKSIZE + 1); i < r/BLOCKSIZE; i++) {
            res += BLOCK[i];
        }

        for (int i = (r/BLOCKSIZE) * BLOCKSIZE; i <= r; i++) {
            res += A[i];
        }

        return res;
    }
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        BLOCK[i/BLOCKSIZE] += A[i];
    }

    for (int i = 1; i <= q; i++) {
        int type; cin >> type;

        if (type == 1) {
            long long k, u; cin >> k >> u;
            update(k, u);
        }

        else {
            long long l, r; cin >> l >> r;
            cout << get(l, r) << '\n';
        }
    }
    
}