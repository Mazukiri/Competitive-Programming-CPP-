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

    while (t--){

    string s; cin >> s;

    //Khoi tao left, right
    int left = -1, right = -1;

    //Find the first '1'
    for (int i = 0; i<s.size(); i++) {
        if (s[i] == '1') {
        left = i;
        break;
    }
    }

    
    //Find the last '1'
    for (int i = s.length()-1; i>=0; i--) 
    {
            if (s[i] == '1') {
                right = i;
                break;
        }
    }


    int ans = 0; int count0 = 0;


    //Co bao nhieu con 0 trong xau
    for (int i = 0; i<s.size(); i++){
        if (s[i] == '0') {
            count0++;
    }}

    for (int i = left; i<=right; i++) if (s[i] == '0') ans++;

    if (count0 == s.size()) cout << 0 << '\n'; else cout << ans << '\n';
}
}

