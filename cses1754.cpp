#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

bool check(int a, int b){

    if ((a>2*b) || (b>2*a)) return false;

    if ((a+b)%3 == 0) return true;

    return false;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int t; cin >> t;

    

    while (t--){
        int a, b; cin >> a >> b;

        if (check(a, b))
         cout << "YES" << '\n'; else cout << "NO" << '\n';
    }
}