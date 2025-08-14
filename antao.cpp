#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e3 + 5;
int dp[N][N];
int A[N][N];
int n, m;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++) {
            cin >> A[i][j];
            dp[i][j] = A[i][j];
        }
    }

    
    //QHĐ
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++){

            dp[i][j] = A[i][j] + max(dp[i][j-1], dp[i-1][j]);
        }
    }
    
    
    cout << dp[n][m];
}