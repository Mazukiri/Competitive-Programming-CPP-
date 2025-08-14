#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    string s; cin >> s;

    int distinctNum = 1;

    for (int i = 1; i<s.size(); i++){
        
        int count = 0;

        for (int j = 0; j<i; j++){
            if (s[j] == s[i]) count++;
        }

        if (count == 0) distinctNum++;

    }

    if (distinctNum % 2 == 0) cout << "CHAT WITH HER!"; else cout << "IGNORE HIM!";
}