#include <bits/stdc++.h>
using namespace std;
const long long N = 20, MOD = 1e9 + 7;
vector<int> adj[N];
long long dp[1 << N][N]; //DP[mask][i] : số cách đi tới thành phố i mà đã đi qua các thành phố ở trong mask 

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n, m; cin >> n >> m;

    for (int i = 1; i<=m; i++){
        
        int u, v; cin >> u >> v;

        //bien chi so thanh 0 -> n-1 de tien hon khi su dung bitmask
        adj[--u].push_back(--v);
    }

    long long M = (1 << n);

    //00001
    dp[1][0] = 1;

    for (int mask = 1; mask<M; mask+=2) //for qua cac so le se luon co bit cuoi la 1
    {
        for (int i = 0; i<n; i++) {
            if (mask >> i & 1) //xoa i bits dau tien va lay bit cuoi (bit i). 
            {
                for (int j: adj[i]){
                    
                    if (!(mask >> j & 1)){ //neu chua di den thi bit = 0 ->> cap nhat kqua

                    int newMask = (mask | (1 << j)); //Bat mask j --> di toi j
                    (dp[newMask][j] += dp[mask][i]) %= MOD; //cap nhat dp[newMask][j]

                    }
                }
            }
        }
    }

    cout << dp[M-1][n-1];

    
}