#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int A[N], prefix[N];
int n, q;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> q;
    for (int i = 1; i<=n; i++) cin >> A[i];

    for (int i = 1; i<=n; i++) prefix[i] = prefix[i-1] + A[i];

    while (q--){
        int l, r; cin >> l >> r;

        cout << prefix[r] - prefix[l-1] << '\n';
    }
}