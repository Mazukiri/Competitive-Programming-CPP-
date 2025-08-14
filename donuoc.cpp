#include <bits/stdc++.h>
using namespace std;
#define int long long
int a,b, N; 

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> a >> b >> N;

    int c = 0;
    

    for (int i = 3; i<=N; i++) {

        c = b*2 - a;
        a = b; 
        b = c;
    }

    cout << c;
}