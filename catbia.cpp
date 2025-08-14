#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int a, b;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    freopen("_ab.inp", "r", stdin);
    freopen("_ab.out", "w", stdout);

    cin >> a >> b;

    int gcd = 1 << __gcd(a, b); //1 << n --> n^2

    cout << a * b / gcd;
}