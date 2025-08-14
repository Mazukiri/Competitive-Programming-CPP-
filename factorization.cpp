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
    //28/2 -> 14/2 -> 7/7/ -> 1

    int divisor = 2;

    while (n > 1){

        while (n%divisor == 0){
            cout << divisor << " ";
            n /= divisor; cout << n << '\n';
        }

        divisor++;
    }
}