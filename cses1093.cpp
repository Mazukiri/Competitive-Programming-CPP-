#include <bits/stdc++.h>
#define int long long int

int mod = 2*(1e9+7);

void solve(){
    int n;
    std::cin >> n;
    int sum = (n*(n+1))/2;
    if(sum%2 != 0){
        std::cout << "0\n";
        return;
    }
    std::vector <int> dp(sum+1);
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=sum; j>0; j--){
            if(j-i >= 0)
                dp[j] = (dp[j]+dp[j-i])%mod;
        }
    }
    std::cout << dp[sum/2]/2 << "\n";
}
     
signed main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    if (fopen("dp.inp", "r")) {
            freopen("dp.inp", "r", stdin);
            freopen("dp.out", "w", stdout);
        }
    

    int t = 1;
    //std::cin >> t;
    while(t--){
        solve();
    }
}