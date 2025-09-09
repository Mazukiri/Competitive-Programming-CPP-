#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 105;
const int W = 1e5 + 5;
ll dp[N][W];
ll n, limit;
ll weights[N], value[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> limit;

    for (int i = 1; i <= n; i++) {
        cin >> weights[i] >> value[i];
    }

    // sort(weights + 1, weights + 1 + n, cmp);

    for (int j = 1; j <= n; j++) {

        for (int i = 1; i <= limit; i++) dp[j][i] = dp[j - 1][i];

        for (int i = limit; i >= weights[j]; i--) {
            dp[j][i] = max(dp[j][i], dp[j - 1][i - weights[j]] + value[j]);
        }
    } 

    // for (int j = 1; j <= n; j++) {
    //     for (int i = limit; i >= weights[j]; i--) {
    //         cout << dp[j][i] << " ";
    //     }

    //     cout << '\n';
    // }

    // cout << '\n';

    cout << dp[n][limit];

    
}