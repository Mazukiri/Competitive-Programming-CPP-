#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

void solve(int x) {
    if (x < 60) {
        string temp = "08:";
        if (x <10) temp += '0';
        temp += to_string(x);
        
        cout << temp << '\n';
    }

    else {
        string temp = "09:";
        x -= 60;
        if (x <10) temp += '0';
        temp += to_string(x);
        
        cout << temp << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        solve(x);
    }
}