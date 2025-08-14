#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
string s; 

string convert(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            s[i] = 'T';
            continue;
        }

        if (s[i] == 'T') {
            s[i] = 'A';
            continue;
        }

        if (s[i] == 'C') {
            s[i] = 'G';
            continue;
        }

        if (s[i] == 'G') {
            s[i] = 'C';
            continue;
        }
    }

    return s;
}



void solve() {

    string number = "", ans = "";

    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            number += s[i];
        }

        else {
            int num = stoi(number);
            number = "";
            for (int occurence = 0; occurence < num; occurence++) ans += s[i];
        }
    }

    cout << convert(ans);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("machdna.inp", "r")) {
        freopen("machdna.inp", "r", stdin);
        freopen("machdna.out", "w", stdout);
    }

    cin >> s;

    solve();

    
}