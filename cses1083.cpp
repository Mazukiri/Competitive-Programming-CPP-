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

    int sumReal = 0;
    int initialSum = (n* (n + 1))/2;

    int b;

    while (cin >> b) sumReal += b;

    cout << initialSum - sumReal;

    
}