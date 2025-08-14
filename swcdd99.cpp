#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int n;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    string ans = "";
    
    for (int i = 1; i<=n/9; i++) ans += '9';
    if (n%9 != 0) ans = to_string(n%9) + ans;

    cout << ans;
}