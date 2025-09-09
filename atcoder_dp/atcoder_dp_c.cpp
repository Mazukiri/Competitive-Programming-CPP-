#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
ll dp[3][N], A[3][N];
int n;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> A[0][i] >> A[1][i] >> A[2][i];

    dp[0][1] = A[0][1];
    dp[1][1] = A[1][1];
    dp[2][1] = A[2][1];

    for (int i = 2; i <=n; i++) {
        dp[0][i] = max(dp[1][i - 1] + A[0][i], dp[2][i - 1] + A[0][i]);
        dp[1][i] = max(dp[0][i - 1] + A[1][i], dp[2][i - 1] + A[1][i]);
        dp[2][i] = max(dp[0][i - 1] + A[2][i], dp[1][i - 1] + A[2][i]);
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << dp[0][i] << " " << dp[1][i] << " " << dp[2][i] <<'\n';
    // }

    ll ans = 0;

    cout << max(max(dp[0][n], dp[1][n]), dp[2][n]);

    
}