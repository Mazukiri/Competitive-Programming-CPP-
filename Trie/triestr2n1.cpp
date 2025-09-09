#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
const int N = 2e6 + 5;
int n;

struct Point {
    string val;
    int id;

    bool operator<(const Point &other) {
        return val < other.val;
    }
} s[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n; 

    int T = n * 2;

    for (int i = 1; i <= T; i++) {
        cin >> s[i].val;
        s[i].id = i;
    }

    sort(s + 1, s + T + 1);

    for (int i = 1; i <= T; i+=2) {
        cout << s[i + 1].id << " " << s[i].id << '\n';
    } 

    
}