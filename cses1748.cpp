#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int A[N], dp[N];
const long long MOD = 1e9+7;
int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("dp.inp", "r")) {
        freopen("dp.inp", "r", stdin);
        freopen("dp.out", "w", stdout);
    }

    int n; cin >> n;
    for (int i = 1; i<=n; i++) cin >> A[i];

    //dp[i]: so day con tang ket thuc tai i (tuc la co lay A[i])

    for (int i = 1; i<=n; i++) dp[i] = 1;

    for (int i = 2; i<=n; i++){
        for (int j = 1; j<i; j++){
            if (A[i] > A[j]) (dp[i] += dp[j])%=MOD;
        }
    }

    long long ans = 0;

    for (int i = 1; i<=n; i++) (ans+= dp[i])%=MOD;

    cout << ans;




    
    
}