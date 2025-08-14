#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n; cin >> n;

    int ans = 1;

    for (int i = 1; i<=n; i++) {
        ans = ans * 2;
        ans %= MOD;
    }

    cout << ans;
}