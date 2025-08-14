#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
string s;
int ans = 1;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> s;

    int dem = 1;

    for (int i = 1; i<s.size(); i++){

        if (s[i] == s[i-1]) dem++; else dem = 1;
        ans = max(ans, dem);
    }

    cout << ans;
}