#include <bits/stdc++.h>  
#define ll long long                                                                                                                                                                                    //Logm
using namespace std;
int n, q; 
const int N = 2e5 + 5, BLOCKSIZE = 450;
map<int, int> cnt;
int lazy[BLOCKSIZE + 5];

void update(int l, int r, int val) {
    for (int i = l; i < (l/BLOCKSIZE + 1) * BLOCKSIZE; i++) {
        apply_lazy(block_l);
        cnt[i/BLOCKSIZE][A[i]]--;
        A[i] += val;
        cnt[i/BLOCKSIZE][A[i]]++;
    }

    for (int i = (l/BLOCKSIZE + 1) * BLOCKSIZE; i < r/BLOCKSIZE * BLOCKSIZE; i++) {
        lazy[i] += val;
    }

    for (int i = r/BLOCKSIZE * BLOCKSIZE; i <= r; i++) {
        cnt[i/BLOCKSIZE][A[i]]--;
        A[i] += val;
        cnt[i/BLOCKSIZE][A[i]]++;
    }
}

ll get(int l, int r, int val) {

    if (l/BLOCKSIZE == r/BLOCKSIZE) {
        cout << cnt[l/BLOCKSIZE][val - lazy[l/BLOCKSIZE]] << '\n';   
    }

    else {

        ll res = 0;

        for (int i = l; i < (l/BLOCKSIZE + 1) * BLOCKSIZE; i++) {
            if (A[i] - lazy[i/BLOCKSIZE] == val) res++;
        }

        for (int i = (l/BLOCKSIZE + 1) * BLOCKSIZE; i < r/BLOCKSIZE * BLOCKSIZE; i++) {
            res += cnt[i][val - lazy[i]];
        }

        for (int i = r/BLOCKSIZE * BLOCKSIZE; i <= r; i++) {
            if (A[i] - lazy[i/BLOCKSIZE] == val) res++;
        }   
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
        cnt[i/BLOCKSIZE][A[i]]++;
    }

    for (int i = 1; i <= q; i++) {
        int typ; cin >> typ;

        if (typ == 1) {
            int l, r, k; cin >> l >> r >> k;
            cout << get(l, r, k) << '\n'; 
        }

        else {
            int l, r, x; cin >> l >> r >> x;
            update(l, r, x);
        }
    }

    
}