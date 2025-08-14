#include <bits/stdc++.h>
using namespace std;

long long test(long long a, long long b, long long k, int power) {
    // Calculate 10^(power+1) using integer arithmetic
    long long factor = 1;
    for (int i = 0; i <= power; ++i) {
        factor *= 10;
    }
    long long ans = factor * a + b;
    if (ans % (k - 10) == 0) return (ans / (k - 10));
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    long long a, b, k; 
    cin >> a >> b >> k;
    
    for (int i = 1; i <= 17; i++) {
        long long ans = test(a, b, k, i);
        if (ans != -1) {
            cout << ans;
            break;
        }
    }
}
