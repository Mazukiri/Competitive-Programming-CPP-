#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int t; cin >> t;

    for (int _ = 1; _ <= t; _++) {
        cin >> n >> m;
        
        for (int i = 1; i<=n; i++) {
            for (int j = 1; j <= m; j++) cin >> A[i][j];
        }

        for (int i = 1; i<=n; i++) {
            for (int j = 1; j <= m; j++) cin >> B[i][j];
        }

        if (isConvertable(A, B)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}