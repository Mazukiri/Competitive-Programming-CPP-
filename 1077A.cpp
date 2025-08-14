#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int t; cin >> t;

    for (int i = 1; i<=t; i++){

        //Enter a, b, k
        int a, b, k; cin >> a >> b >> k;
        
        //Init the start 
        long long start = 0;

        //Calculate the rightJump and leftJump
        long long rightJump = a * (k/2);
        long long leftJump = b * (k/2);

        //Check whether k is odd. If so, we have to jump a units to the right!
        if (k%2 == 1) rightJump = rightJump + a;

        //Calculate the final destination
        start = start + rightJump;
        start = start - leftJump;
        
        cout << start << '\n';
    }
}