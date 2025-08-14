#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int y;
int factorial[15];
int digit[15];

void init(){
    factorial[0] = 1;
    for (int i = 1; i<10; i++){
        factorial[i] = factorial[i-1] * i;
    }
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> y;

    if (y == 1) return cout << 0, 0;

    init();

    for (int i = 9; i>=0; i--) {
        
        if (y>0){
            digit[i] = y/factorial[i];
            y -= (digit[i]*factorial[i]);
        }
    }

    string ans = "";

    for (int i = 1; i<=9; i++) {
        for (int j = 1; j<=digit[i]; j++) ans += to_string(i);
    }

    cout << ans;
}