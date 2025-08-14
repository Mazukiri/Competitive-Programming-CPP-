#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int to_100 = 0, to_20 = 0, to_10 = 0, to_5 = 0, to_1 = 0;

    long long n; cin >> n;

    //tinh tong so to 100
    to_100 = n/100;
    n = n - to_100 * 100;

    //tinh tong so to 20
    to_20 = n/20;
    n = n - to_20 * 20;

    //tinh tong so to 10
    to_10 = n/10;
    n = n - to_10 * 10;

    //Tinh tong so 5
    to_5 = n/5;
    n = n - to_5 * 5;

    //Tinh tong to 1
    to_1 = n;
    n = n - n;

    //Greedy Algorithm
    cout << to_100 + to_20 + to_10 + to_5 + to_1;
}