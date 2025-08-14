#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int n;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    if (n == 1) {
        cout << 1;
        return 0;
    }

    if (n<=3) {
        cout << "NO SOLUTION";
        return 0;
    }

    if (n == 4) {
        cout << 2 << " " << 4 << " " << 1 << " " << 3;
        return 0;
    }

    //In ra so le
    for (int i = n; i >= 1; i = i - 2) cout << i << " ";
    for (int i = n-1; i >= 1; i = i - 2) cout << i << " ";
    
}