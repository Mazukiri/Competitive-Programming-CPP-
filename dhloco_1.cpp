#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int dp[N]; //dp[i]: số cách nhảy tại i chia cho số M (K%M)
int n, MOD;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> MOD;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    //dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

    if (n<=3){
        cout << (dp[n]%MOD);
        return 0;
    }

    else {

        for (int i = 4; i<=n; i++) {
             dp[i] = ((dp[i-1] + dp[i-2])%MOD + dp[i - 3])%MOD;
        }
    }

    cout << dp[n];


    
}