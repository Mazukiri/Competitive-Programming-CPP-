#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, S;
int dp[N]; //Số đồng xu nhỏ nhất dùng để biểu diễn số tiền i
int V[N];
int coinSelectAt[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> S;

    for (int i = 1; i<=n; i++) cin >> V[i];

    for (int i = 1; i<=S; i++) dp[i] = S + 1;

    for (int i = 1; i<=S; i++){
        for (int j = 1; j<=n; j++){

            if (i >= V[j] && dp[i] > dp[i- V[j]] + 1) {
                dp[i] = dp[i- V[j]] + 1;
                coinSelectAt[i] = V[j];
        }
    }

    cout << dp[S] << '\n';

    
    while (S > 0){

        int temp = S + 1;
        int ans;

        for (int i = 1; i<=n; i++) {
            
            if (S >= V[i] && dp[S - V[i]] + 1 < temp) {
                
                temp = dp[S - V[i]] + 1;
                ans = V[i];
                
            }
        }

        cout << ans << " ";
        S -= ans;   
    }

    
}
