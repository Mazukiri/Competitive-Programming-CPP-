#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

int count1[26], count2[26];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

   string s1, s2, s3; cin >> s1 >> s2 >> s3;

   string s4 = s1 + s2;

   sort(s3.begin(), s3.end());
   sort(s4.begin(), s4.end());

   if (s3 == s4) cout << "YES"; else cout << "NO";
}