#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    long long n; cin >> n; 
    long long ans = (n - 1) * (n-1) * 6;
    ans = ans - (2 * (n-2) * (n-1));
    cout << ans;

}