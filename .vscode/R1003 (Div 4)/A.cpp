#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n; cin >> n;

    for (int i = 1; i<=n; i++){
        string s; cin >> s;
        s.pop_back();
        s.pop_back();
        s.push_back('i');
        cout << s << '\n';
    }
}