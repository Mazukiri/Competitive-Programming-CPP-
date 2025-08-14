#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int n; 
int A[1000005];


int factorization(int x){

    for (int i = 2; i<=ceil(sqrt(x)); i++) 
        if (x%i == 0) return i;
    return x;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    for (int i = 1; i<=n; i++) cin >> A[i];

    int kq = A[1];

    for (int i = 2; i<=n; i++) kq = __gcd(kq, A[i]);

    kq = factorization(kq);
    
    if (kq == 1) cout << -1; else cout << kq;
}