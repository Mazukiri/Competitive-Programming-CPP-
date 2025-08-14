#include <bits/stdc++.h>
using namespace std;
#define int long long
int grid[4][4], grid2[4][4];
int cnt[3], cnt2[3];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int t; cin >> t;

    while (t--){

    for (int i = 0; i<3; i++){
        cnt[i] = 0;
        cnt2[i] = 0;
    }

    for (int i = 1; i<=3; i++){
        for (int j = 1; j<=3; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'W') cnt[0]++;
            if (grid[i][j] == 'B') cnt[1]++;
            if (grid[i][j] == '.') cnt[2]++;
        }
    }



    for (int i = 1; i<=3; i++){
        for (int j = 1; j<=3; j++) {
            cin >> grid2[i][j];
            if (grid2[i][j] == 'W') cnt2[0]++;
            if (grid2[i][j] == 'B') cnt2[1]++;
            if (grid2[i][j] == '.') cnt2[2]++;
        }
    }

    if (grid[2][2] != grid2[2][2]) {
        cout << "NO" << '\n';
        continue;
    }

    if (cnt[0] != cnt2[0] || cnt[1] != cnt2[1]) {
        cout << "NO" << '\n';
        continue;
    }

    else {

        int order = 0;

        if (cnt[2] == 0) {

            for (int i = 1; i<=3; i++){
                for (int j = 1; j<=3; j++){
                    if (grid[i][j] != grid2[i][j]) {
                    cout << "NO" << '\n';
                    order++;
                    break;
                    }      
                }
            }    
        }
        
        if (order == 0) cout << "YES '\n"; 
    }
}

    
}