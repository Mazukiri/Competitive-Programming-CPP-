#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("DONGNUOC.inp", "r")) {
        freopen("DONGNUOC.inp", "r", stdin);
        freopen("DONGNUOC.out", "w", stdout);
    }

    long long N; cin >> N;

    long long ans = N/5;

    if (N%5 == 0) cout << ans << '\n';
    if (N%5 == 1) cout << ans + 1 << '\n';
    if (N%5 == 2) cout << ans + 1 << '\n';
    if (N%5 == 3) cout << ans + 1 << '\n';
    if (N%5 == 4) cout << ans + 2 << '\n';
}