#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
#define ll long long
using namespace std;
int S, q;
ll heavy[715][715];

void process(int x, int y) {
    //heavy[x][y] : sum of all the numbers that has index % x = y
    
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> q; 

    S = round(sqrt(q));

    for (int i = 1; i <= q; i++) {
        int typ, x, y; 
        cin >> typ >> x >> y;

        if (typ == 1) {
            A[x] += y;
        }

        else {
            if (x > S) {
                process();
            }

            else {
                ll ans = 0;
                for (int index = y; index <= n; index += x) {
                    ans += A[index];
                }
                cout << ans << '\n';
            }
        }
    }
}