#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n,t; cin >> n >> t;

    if ((t == 10) && (n == 1)) {
            cout << "-1";
            return 0;
    }

    if (t == 10) {

        cout << t;
        for (int i = 1; i <=n-2; i++) cout << "0";
        return 0;
    }

    cout <<t;
    for (int i = 1; i<=n-1; i++) cout <<0;

}