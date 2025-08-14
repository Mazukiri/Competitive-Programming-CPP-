#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;
bool f[N];

void sieve(){
    
    for (int i = 2; i<=N; i++) f[i] = true;
    for (int i = 2; i<=N; i++) 
        if (f[i]) for (int j = i; j<=N/i; j++) f[i*j] = false;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("gol.inp", "r")) {
        freopen("gol.inp", "r", stdin);
        freopen("gol.out", "w", stdout);
    }

    cin >> n; 

    sieve();

    int ans = 0;

    for (int i = 2; i<=n/2; i++){
        if ((f[i]) && (f[n-i])) ans++;
    }

    cout << ans;

    
}