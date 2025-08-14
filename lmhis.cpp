#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("dp.inp", "r")) {
        freopen("dp.inp", "r", stdin);
        freopen("dp.out", "w", stdout);
    }

    int n; cin >> n;
    ll A[n+1]; ll W[n+1]; ll dp[n+1];
    
    for (int i = 1; i<=n; i++) cin >> A[i];
    for (int i = 1; i<=n; i++) cin >> W[i];
    for (int i = 1; i<=n; i++) dp[i] = 1;

    ll ans = 0;
    ll last = 0;
    //DP 

    for (int i = 1; i<=n; i++) {
        ll sum = 0;
        for (int j = 1; j<i; j++) {

            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j]+1);
                sum = max(sum, sum + W[j]);
            }
    }

        ans = max(sum, ans);
        if (ans == sum) last = i;
    }

    cout << ans << " " << last;

    
}