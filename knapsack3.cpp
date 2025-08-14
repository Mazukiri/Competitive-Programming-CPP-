#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long W[N], V[N];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    long long n, m ; 
    cin >> n >> m;

    for (int i = 0; i<n; i++){
        cin >> W[i] >> V[i];
    }

    int totalMask = (1 << n); //2^n

    long long ans = 0; //ans: gia tri lon nhat satisfy m
    long long truyvet;

    for (int mask = 0; mask < totalMask; mask++){

        long long weight = 0, value = 0;

        for (int i = 0; i<n; i++){

            if (mask >> i & 1) {
                
                weight += W[i];
                value += V[i];
            }
        }

        if (weight <= m) {
            
            if (value > ans){
                ans = max(ans, value);
                truyvet = mask;
            }
        }
    }

    cout << __builtin_popcount(truyvet) << '\n';

    for (int i = 0; i<n; i++){
        if ((truyvet >> i) & 1) cout << i+1 << " ";
    }





    
}