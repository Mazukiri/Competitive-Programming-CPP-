#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const long long N = 16;
long long hpBoss[N];
char board[N][N];

long long dp[1 << N]; //dp[i]: so nhat chem toi thieu de tieu diet quat vat thu i

long long numShots(long long a, long long b){
    
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

    for (int t = 1; t<=q; t++){

        memset(dp, 0x3f, sizeof(dp));
        

        int n; cin >> n; 



        int M = (1 << n);

        for (int i = 0; i<n; i++) cin >> hpBoss[i];

        for (int i = 0; i<n; i++){
            for (int j = 0; j<n; j++){
                cin >> board[i][j];
                board[i][j] -= '0';
            }
        }

        dp[0] = 0;

        for (int mask = 0; mask < M; mask++){

            for (int i = 0; i<n; i++){
            
            if (!((mask >> i) & 1)){   
                //Neu bit 1 bat thi ta co the lay thanh kiem do
                int power = 1;
                for (int j = 0; j<n; j++) if (mask >> j & 1) power = max(power, (int) board[j][i]);
            

                int newMask = (mask | (1 << i)); //bat bit 1
                

                dp[newMask] = min(dp[newMask], dp[mask] + numShots(power, hpBoss[i]));
            }
            }
        }

        cout << "Case " << t << ": " << dp[M - 1] << '\n';
        

        
        
    }
}