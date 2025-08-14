#include <bits/stdc++.h>
using namespace std;

const long long N = 1e6 + 5;
long long A[N], F[N];
int n; 

void snt(){

    for (int i = 1; i<=1000000; i++) F[i] = true;
    F[1] = false;


    for (int i = 2; i<=1000000; i++){

        if (F[i]) for (int j = 2; j<=1000000/i; j++) F[i*j] = false;
    }
}

void solve(){
    long long countPrime = 0;

    long long ans = n+1;
    long long lastPrimeIndex = 0;

    snt();

    for (int i = 1; i<=n; i++){

        if (F[A[i]]) {
            
            countPrime++;
            if (countPrime <2) lastPrimeIndex = i;
            
            if (countPrime > 1) {
                ans = min(ans, i - lastPrimeIndex + 1);
                lastPrimeIndex = i;
            }

        }
    }

    if (ans != n+1) cout << ans; else cout << -1;
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("DAYCON.inp", "r")) {
        freopen("DAYCON.inp", "r", stdin);
        freopen("DAYCON.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i<=n; i++) cin >> A[i];
    snt();
    solve();
    
    
}