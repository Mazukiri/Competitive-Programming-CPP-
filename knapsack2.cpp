#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long DP[N];
int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("dp.inp", "r")) {
        freopen("dp.inp", "r", stdin);
        freopen("dp.out", "w", stdout);
    }

    long long n, totalWeight; cin >> n >> totalWeight;

    for (int i = 1; i<=n; i++) cin >> weight[i] >> value[i];

    for (int i = 1; i<=n; i++){
        
        for (int w = totalWeight; w>=weight[i]; w--) 
    }
    
}