#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n; cin >> n;

    int ans = n/2; cout << ans << '\n';

    for (int i = 1; i<ans; i++) cout << 2 << " ";

    if (n%2 == 0) cout << 2; else cout << 3;
    
}