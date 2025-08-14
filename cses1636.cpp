#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
const long long N = 1e6+5;
int dp[N], A[N];


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("dp.inp", "r")) {
        freopen("dp.inp", "r", stdin);
        freopen("dp.out", "w", stdout);
    }

    /*
    dp[i]: so cach co tong la i
    DP[i] = sum(1..n) (DP[i-A[j]]) 
    Tai sao lai khong +1 o moi DP[i-A[j]]??? So cach khong tang len (vì với mỗi cách
    chỉ thêm vào +A[j]!!!
    So cach de tao ra i dua tren cac A[i - j] (1<= j <= 6)
    Cong thuc tong quat: f[i] = f[i-a] * p1 + f[i-b] * p2 + f[i-c] * p3.....
    dp[0] = 1;
    */

    int n,x; cin >> n >> x;
    for (int i = 1; i<=n; i++) cin >> A[i];
    dp[0] = 1;
    
    /*
    DP[i] chi co the duoc tao ra bang DP[i - {cac menh gia kha thi}]
    
    De tao ra menh gia la i, thi to tien cuoi cung nam trong doan tu A[1->n]
    --> Gia tri ma truoc do can tao ra de co tong bang i la: i - A[j]. 
    So cach de tao ra i - A[j] la DP[i - A[j]]
    Neu (i - A[j] < 0) --> Khong the tao ra i tu i - A[j] 

    */
   for (int j = 1; j<=n; j++){
        for (int i = 1; i<=x; i++){
            if (i - A[j] >= 0) (dp[i] += dp[i - A[j]])%=MOD;
        }
    }

    cout << dp[x];
}