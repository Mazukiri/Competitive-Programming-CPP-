#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    string s; getline(cin, s);

    string ans = "";

    

    vector<char> v;

    if (s[0] != ' ') v.push_back(s[0]);

    int index = 1;

    while (index < s.size()){

        if (s[index] != ' ') v.push_back(s[index]);
        if ((s[index] == ' ') && (s[index - 1] != ' ')) v.push_back(s[index]);
        index++;
    }

    for (auto x: v) cout << x;
    cout << '\n';
}