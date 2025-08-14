#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n, m; cin >> n >> m;

    //Bai toan da tro thanh tim boi so cua M tren khoang n/2 -- > n

    int minsteps = n/2; 

    if (n%2 == 1) minsteps++; //11

    int maxsteps = n; //21

    int ans = minsteps/m;

    //m = n: n
    //m < n: 
    //m > n: -1


    if (minsteps % m == 0) {
        cout << minsteps;
        return 0;
    }

    ans = m * ((minsteps/m)+1);

    if (ans <= n) cout << ans; else cout << -1;

    //n/2 <= m * x <= n //1 -> vc

    //21: 10 1 = 11
    //21: 9 3 = 12
    //21: 8 5 = 13
    //21: 7 7 = 14
    //21: 6 9 = 15
    //21: 5 11 = 16
    //21: 4 13 = 17
    //21: 3 15 = 18
    //21: 2 17 = 19
    //21: 1 19 = 20
    //21: 0 21 = 21

    // n/2 --> n
    // n/2 + 1 --> n
    /* while (minsteps % m != 0 && minsteps <=n) {
        cout <<  minsteps << '\n';
        minsteps++;
    }


    if (minsteps%m != 0) cout << -1; else cout << minsteps;

    */

   

   




}