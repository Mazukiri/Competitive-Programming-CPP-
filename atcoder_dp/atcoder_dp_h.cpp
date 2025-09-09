#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 5;
const ll MOD = 1e9 + 7;
ll dp[N][N];
char grid[N][N];
int H, W;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> H >> W;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '.') dp[i][j] = 1;
        }
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (i == 1 && j == 1) continue;
            if (grid[i][j] != '#') dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }

    cout << dp[H][W];

    



    
}