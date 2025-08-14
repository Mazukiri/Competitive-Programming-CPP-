#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k){
    
    if (n == 1){
        cout << 0 << '\n';
        return;
    }

    if ((n<k) || (n == k)) {
        cout << 1 << '\n';
        return;
    }

    if (k == 2){
        cout << n-1 << '\n';
        return;
    }

    int ans = n/(k-1);
    n = n - (ans * (k-1));
    if (n <= 1) cout << ans << '\n'; else cout << ans + 1 << '\n';
    
}


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int t; cin >> t;

    for (int i = 1; i<=t; i++) {
        int n,k; cin >> n >> k;
        solve(n, k);
    }
    
}