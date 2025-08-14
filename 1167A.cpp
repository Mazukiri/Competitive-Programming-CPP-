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

    for (int i = 1; i<=t; i++)
    {
        int n; cin >> n;
        string s; cin >> s;
        
        if (n<11) {
            cout << "NO" << '\n';
            continue;
        }

        int index = -1;

        for (int i = 0; i<n; i++) {
            if (s[i] == '8'){
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "NO" << '\n';
            continue;
        }

        if (n - index <11) cout << "NO" << '\n'; else cout << "YES" << '\n';
    }
}
