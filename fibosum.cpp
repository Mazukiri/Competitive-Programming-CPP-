#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;
int n, expo;


int exponential(int n, int expo){

    if (expo == 0) return 1;
    if (expo == 1) return n;

    int t = exponential(n, expo/2); //exponential(2, 5)
    //exponential(2, 2) = 4
    //exponential(2, 1) = 2

    if (expo%2 == 0) return (t*t)%MOD;
    else return (((t*t)%MOD)*n%MOD);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> expo >> MOD;

    int a = (exponential(n, expo+1)-1)%MOD;
    int b = (n - 1)%MOD;
    cout << (a/b)%MOD;
}