#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first //cay oliu
#define se second ///cypress
const int N = 1e6 + 5;
int V[N], W[N];
int dp[N];
int Q, M, K;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    
        cin >> Q >> M >> K;

        int index = 0;

        for (int i = 1; i<=M; i++) {
            int x; cin >> x;
            index++;
            V[index] = x;
            W[index] = x;
            
        }

        for (int i = 1; i<=K; i++){
            int x; cin >> x;
            index++;
            V[index] = x - 1;
            W[index] = x;
        }

        

        int n = K + M;

        //for (int i = 1; i<=n; i++) cout << W[i] << " " << V[i] << '\n';
        
        for (int i = 1; i<=n; i++){
            for (int w = Q; w>=W[i]; w--){
                
                dp[w] = max(dp[w], dp[w - W[i]] + V[i]);
            }
        }

        /*
        for (int i = 1; i<=n; i++){
            for (int j = 1; j<=Q; j++) cout << dp[i][j] << " ";
            cout << '\n';
        }
        */

        cout << dp[Q];
    
}