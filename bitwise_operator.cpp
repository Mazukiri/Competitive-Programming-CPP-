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

    for (int i =1; i<=t; i++){

        int n; cin >> n;
        if (n & 1 == 1) cout << "Odd" << '\n'; else cout << "Even" << '\n';
    }

    
    
}