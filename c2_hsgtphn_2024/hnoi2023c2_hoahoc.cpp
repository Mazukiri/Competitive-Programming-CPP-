#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("HOAHOC.inp", "r")) {
        freopen("HOAHOC.inp", "r", stdin);
        freopen("HOAHOC.out", "w", stdout);
    }

    int a, b; cin >> a >> b;

    a = a/3;
    b = b/2;

    int c = min(a, b); 
    cout << c;
}
