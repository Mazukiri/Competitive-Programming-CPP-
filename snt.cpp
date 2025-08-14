#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int q;
int isPrime[N];

void sieve(){

    for (int i = 1; i<=N; i++) isPrime[i] = i;

    for (int i = 2; i<=N; i++){
        if (isPrime[i] == i) {

            for (int j = 2; j<=N/i; j++) isPrime[i*j] = i;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    sieve();

    int n; cin >> n;

    int ans = 1; 

    while (n > 1){

        int divisor = isPrime[n];

        int mu = 0;

        while (n%divisor == 0) {
            mu++;
            n /= divisor;
        }

        ans *= (mu+1);
    }

    cout << ans;

    
}