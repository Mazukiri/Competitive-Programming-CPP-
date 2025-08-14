#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
string s;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int q; cin >> q;

    while (q--) {
        
        cin >> s;

        int cU = 0, cI = 0;

        bool flag = false;

        for (int i = 0; i < s.size(); i++) {
            
            if (s[i] == 'U') cU++;
            else cI++;

            if (cI >= cU * 2 && cU > 0 && cI > 0) {
                cout << "YES" << " " << 1 << " " << i + 1 << '\n';
                flag = true;
                break;
            }

            if (cU >= cI * 2 && cU > 0 && cI > 0) {
                cout << "YES" << " " << 1 << " " << i + 1 << '\n';
                flag = true;
                break;
            }
        }

        if (!flag) cout << "NO" << '\n';
        
    }

    
}