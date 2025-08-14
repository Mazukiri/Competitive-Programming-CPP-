#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isPrime(int n){
    for (int i = 2; i<=ceil(sqrt(n)); i++) {
        if (n % i == 0) return false;
    }

    return true;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("UOCCHUNG.inp", "r")) {
        freopen("UOCCHUNG.inp", "r", stdin);
        freopen("UOCCHUNG.out", "w", stdout);
    }

    int a, b; cin >> a >> b;

    if (__gcd(a, b) == 1) {
        cout << -1;
        return 0;
    }

    int gcd = __gcd(a, b);
    int c = ceil(sqrt(gcd));

    int ans = 0;

    if (isPrime(gcd)) {
        cout << 1;
        return 0;
    }

    for (int i = 2; i<=c; i++){
        if (gcd % i == 0){
            ans = gcd/i;
            cout << ans;
            return 0;
        }
    } 
}