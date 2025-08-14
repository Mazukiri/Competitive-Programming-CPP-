#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    string s; cin >> s;

    int index = 0;

    for (int i = 0; i<s.size(); i++){

        if ((s[i] == 'h') && (index == 0)) {
            index++;
        }

        if ((s[i] == 'e') && (index == 1)) {
            index++;
        }

        if ((s[i] == 'l') && (index == 2)) {
            index++;
        }

        if ((s[i] == 'l') && (index == 3)) {

            index++;
        }

        if ((s[i] == 'o') && (index == 4)) {
            hello[index] = s[i];
            index++;
        }
    }

    if (index == 5) cout << "YES"; else cout << "NO";
}

