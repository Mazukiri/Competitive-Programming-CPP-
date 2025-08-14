#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("dp.inp", "r")) {
        freopen("dp.inp", "r", stdin);
        freopen("dp.out", "w", stdout);
    }

    int n; cin >> n;
    int dp[n+1], A[n+1];

    //dp[i] = luu day con tang dai nhat toi A[i]

    for (int i=1; i<=n; i++) cin >> A[i];

    for (int i = 1; i<=n; i++) dp[i] = 1;

    for (int i = 2; i<=n; i++){
        for (int j = 1; j<i; j++){
            
            if (A[i] > A[j]) dp[i] = max(dp[i], dp[j]+1);
        }
    }

    int ans = 0;

    for (int i = 1; i<=n; i++) ans = max(ans, dp[i]);
    cout << ans;


    
    
}