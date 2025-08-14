#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int t; cin >> t;
    cin.ignore();  // Ignore the newline after reading `t`

    for (int k = 1; k <= t; k++) {
        string s; 
        getline(cin, s);

        string result;
        
        for (char c : s) {
            if (!result.empty() && result.back() == c) {
                result.pop_back();  // Collapse duplicate
            } else {
                result.push_back(c);
            }
        }

        cout << result.size() << '\n';
    }
}