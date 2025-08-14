#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
const long long N = 1e6+5;
int dp[N];


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("dp.inp", "r")) {
        freopen("dp.inp", "r", stdin);
        freopen("dp.out", "w", stdout);
    }

    //dp[i]: so cach co tong la i
    //DP[i] = DP[i-1] + DP[i-2] + DP[i-3] + DP[i-4] + DP[i-5] + DP[i-6]
    //Tai sao lai khong +1 o moi DP[i-j]??? Boi vi no da them +j vao tat ca
    //So cach de tao ra A[i] dua tren cac A[i - j] (1<= j <= 6)
    //Cong thuc tong quat: f[i] = f[i-a] * p1 + f[i-b] * p2 + f[i-c] * p3.....
    dp[0] = 1;

    int n; cin >> n;
    

    for (int i = 1; i<=n; i++){
        for (int j = max(i-6, 0); j<=i-1; j++){
            (dp[i] += dp[j])%=MOD;
        }
    }

    cout << dp[n];
}