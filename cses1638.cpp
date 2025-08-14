#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3+5;
const long long MOD = 1e9+7;
int DP[N][N];
char A[N][N];


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("dp.inp", "r")) {
        freopen("dp.inp", "r", stdin);
        freopen("dp.out", "w", stdout);
    }

    int n; cin >> n;

    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++){
            cin >> A[i][j];
        }
    }

    for (int i = 0; i<=n; i++){
        for (int j = 0; j<=n; j++){
            DP[i][j] = 0; //base case
        }
    }

    //DP
    DP[1][1] = 1;
    
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++){
            
            if ((A[i][j] == '.') && ((A[i-1][j] == '.'))) (DP[i][j] += DP[i-1][j])%=MOD;
            if ((A[i][j] == '.') && ((A[i][j-1] == '.'))) (DP[i][j] += DP[i][j-1])%=MOD;
            
        }
    }
    
    if (A[1][1] == '*') DP[1][1] = 0;
    
    cout << DP[n][n];

    
    
}