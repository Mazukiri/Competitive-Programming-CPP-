#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
int f[N], g[N];
int n, k;

int binpow(int x, int power) {
    if (power == 0) return 1;
    if (power == 1) return x;

    int t = binpow(x, power/2);

    if (power % 2 == 0) return t * t % MOD;
    
    else {
        return (t * t % MOD) * x % MOD;
    }
}

int comb(int k, int n) {

    return (((f[n] * g[k]) % MOD) * g[n - k]) % MOD;
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    /*
    The entire formula is: nCk * k^(n - k).
    As we're required to calculate with MOD, we'll have to use the specific nCk formula
    that satisfy this condition 
    */

    cin >> n >> k;

    f[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = (f[i - 1] * i) % MOD;
    
    g[n] = binpow(f[n], MOD - 2) % MOD;

    for (int i = n - 1; i >= 1; i--) {
        g[i] = (g[i + 1] * (i + 1)) % MOD;
    }

    int ans = binpow(k, n) % MOD;

    int diff = 0;

    for (int i = 1; i <=k; i++) {
        int currSum = (binpow(-1, i) * comb(i, k)) % MOD * binpow(k - i, n) % MOD;        
        diff += currSum ;
        diff %= MOD;
    }



    cout << (ans + diff) % MOD;


    //cout << binpow(2, 4);
}