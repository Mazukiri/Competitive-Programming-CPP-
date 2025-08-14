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
    int i = 2;
    int ans = 1;
    int lim = ceil(sqrt(n));

    for (int i = 2; i<=lim; i++){
        if (n%i == 0) break;
        if ((n%i != 0) && (i == lim)) {
            cout << n << '\n' << 2;
            return 0;
        }
    }


    while (n>1){

        int dem = 0;
        
        while (n%i == 0) {
            dem++;
            if (n/i == 1) cout << i; else cout << i << "*";
            n = n/i;
        }

        if (dem != 0) ans *= (dem+1);

        i++;

    }

    cout << '\n' << ans;
}