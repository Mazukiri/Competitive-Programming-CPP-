#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const long long N = 1e6 + 5;
int n, m;
vector<int> v;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 1; i<=n+m; i++){
        int x; cin >> x; v.push_back(x);
    }

    sort(v.begin(), v.end());

    for (auto x: v) cout << x << " ";

    
}