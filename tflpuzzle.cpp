#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
const int INF = 1e18 + 7;
int n, q;
string ans, s;
char converted[30];


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("PUZZLE.inp", "r")) {
        freopen("PUZZLE.inp", "r", stdin);
        freopen("PUZZLE.out", "w", stdout);
    }

    cin >> n >> q;

    cin >> s;

    for (char i = 'a'; i <= 'z'; i++) converted[i] = i;

    while (q--) {
        char u, v; cin >> u >> v;
        for (int i = 'a'; i<='z'; i++) {
            if (i == u) {
                converted[i] = v;
                continue;
            }
            
            if (converted[i] == u) converted[i] = v;
        }
    }

    // for (char i = 'a'; i <= 'z'; i++) cout << i << " " << converted[i] << '\n';

    // cout << s << '\n';    

    ans = "";

    for (int i = 0; i<s.size(); i++) {
        ans += converted[s[i]];
    }

    cout << ans;

    

    
}



