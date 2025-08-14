#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int t; cin >> t;
    
    for (int i = 1; i<=t; i++){

        int a, b, c; cin >> a >> b >> c;
    
        if (c == 0) cout << "NO CURVE" << '\n';    
        if (c > 0) cout << "CURVE UP" << '\n';    
        if (c < 0) cout << "CURVE DOWN" << '\n';    
    }
    
}