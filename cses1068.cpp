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

    cin >> n; cout << n << " ";

    while (n != 1) {
        if (n%2 == 0) {
            n /= 2;
            cout << n << " ";
            continue;
        }

        else {
            n*=3;
            n++;
            cout << n << " ";
            continue;
        }
    }   
}