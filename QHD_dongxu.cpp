#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e3 + 10;
int f[N], currency[N], n, S;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> S;

    for (int i = 1; i<=n; i++) cin >> currency[i];

    f[0] = 0;

    for (int i = 1; i<=S; i++) f[i] = S + 1;

    for (int sum = 1; sum <= S; sum++){
        for (int ith = 1; ith <= n; ith++){

            if (sum >= currency[ith]) f[sum] = min(f[sum], f[sum - currency[ith]] + 1);
        }
    }

    if (f[S] == S+1) cout << -1; else cout << f[S];
} 