#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const long long N = 16;
long long hpBoss[N];
long long board[N][N];
long long M = (1 << N);
long long dp[M]; //dp[i]: so nhat chem toi thieu de tieu diet quat vat thu i

long long numShots(int a, int b){
    
    long long ans = b/a;
    
    if (b%a != 0) ans++;

    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int q; cin >> q; 

    for (int i = 1; i<=q; i++){

        int n; cin >> n; 

        for (int i = 0; i<n; i++) cin >> hpBoss[i];

        for (int i = 0; i<n; i++){
            for (int j = 0; j<n; j++){
                cin >> board[i][j];
            }
        }

        for (int mask = 0; mask < M; mask++){

            int power = 1;

            for (int i = 0; i<n; i++){
            
            if ((!(mask >> i) & 1)){   
                //Neu bit 1 bat thi ta co the lay thanh kiem do
                for (int j = 0; j<n; j++) if (mask >> i & 1) power = max(power, A[j][i]);
            

                int newMask = (mask | (1 << i)); //bat bit 1
                

                dp[newMask] = min(dp[newMask], dp[mask] + numShots(power, hpBoss[i]));
            }
            }
        }

        cout << dp[M-1];

        
        
    }
}