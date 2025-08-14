#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }
    int C, N;
    cin >> C >> N;
    
    vector<int> w(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> w[i];
    }
    
    vector<int> dp(C+1, 0);
    
    for (int i = 1; i <= N; i++) {
        for (int j = C; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
        }
    }
    
    cout << dp[C];

}
