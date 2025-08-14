#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int V[N];
int dp[N]; 
int n, S;

//dp[i]: Số tờ tiền ít nhất cần thiết để tạo thành i
//dp[5]:

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    //Cho n đồng tiền có mệnh giá V1, V2, ... V[n]. 
    //Cho một số tiền S. Tính xem cần tối thiểu bao nhiêu tờ tiền để tạo ra S
    // S<=1000, n<=1000

    cin >> n >> S;

    for (int i = 1; i<=n; i++) cin >> V[i];

    for (int i = 1; i<=S; i++) dp[i] = S + 1;
    //QHĐ
    for (int currentMoney = 1; currentMoney<=S; currentMoney++) 
    {
        //i = 2
        for (int j = 1; j<=n; j++){

            if (V[j] <= currentMoney && dp[currentMoney - V[j]] + 1 < dp[currentMoney]) 
                dp[currentMoney] = dp[currentMoney - V[j]] + 1;
        }
    }

    cout << dp[S];
}