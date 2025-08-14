#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int n; //2^63

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    int factor_1 = 0;
    int factor_2 = 1;

    if (n == 1) cout << factor_1;
    if (n >= 2) cout << factor_1 << " " << factor_2 << " ";


    for (int i = 3; i<=n; i++){
        
        int next_factor = factor_1 + factor_2; 
        cout << next_factor << " ";
        factor_1 = factor_2; 
        factor_2 = next_factor; 
    }
}