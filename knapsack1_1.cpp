#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, maxWeight;
int W[N], V[N];
int dp[105][N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> maxWeight;

    for (int i = 1; i<=n; i++){
        cin >> W[i] >> V[i];
    }

    for (int i = 1; i<=n; i++){
        
            for (int w = 1; w<=maxWeight; w++) {
        
            if (w < W[i]) dp[i][w] = dp[i-1][w];

            else dp[i][w] = max(dp[i-1][w], dp[i-1][w- W[i]] + V[i]);
        }       
    }

    // for (int i = 1; i<=n; i++){
    //     for (int j = 1; j<=maxWeight; j++) cout << dp[i][j] << " ";
    //     cout << '\n';
    // }

    cout << dp[n][maxWeight];
}