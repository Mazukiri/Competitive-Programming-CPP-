#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int ans = 0;

    int n; cin >> n;

    for (int i = 2; i<=n; i++){
        if (n%i == 0) ans++;
    }

    cout << ans;
    
}