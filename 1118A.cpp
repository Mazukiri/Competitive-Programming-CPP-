#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int q; cin >> q;

    for (int i = 1; i<=q; i++){
        int n, a, b; cin >> n >> a >> b;

        if (a*2 <= b) cout << n*a << '\n';
        if (a*2 > b) cout << (n/2) * b + (n%2)*a << '\n';
    }
}