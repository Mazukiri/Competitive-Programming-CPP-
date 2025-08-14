#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
int n, H, L;
int horrorIndex[1000005];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> H >> L;
    //Loop through all possible cases
    //and update where it need to

    for (int i = 0; i<=n-1; i++){
        horrorIndex[i] = MOD;
    }

    for (int i = 1; i<=H; i++) {
        int x; cin >> x;
        horrorIndex[x] = 0;
    }

    for (int i = 1; i<=L; i++) {
        
        int a, b; cin >> a >> b;

        if (horrorIndex[a] == 0 && horrorIndex[b] == 0) continue;

        if (horrorIndex[a] == 0){
            if (horrorIndex[b] == MOD) horrorIndex[b] = 1; 
            continue;
        }

        if (horrorIndex[b] == 0){
            if (horrorIndex[a] == MOD) horrorIndex[a] = 1;
            continue;
        }

        if (horrorIndex[a] == MOD && horrorIndex[b] == MOD) continue;

        if (horrorIndex[a] == MOD && horrorIndex[b] > 0 && horrorIndex[b] < MOD){
            
            horrorIndex[a] = horrorIndex[b] + 1;
            continue;
        }

        if (horrorIndex[b] == MOD && horrorIndex[a] > 0 && horrorIndex[a] < MOD){
            
            horrorIndex[b] = horrorIndex[a] + 1;
            continue;
        }

        if (horrorIndex[a] > 0 && horrorIndex[a] < MOD
            && horrorIndex[b] > 0 && horrorIndex[b] < MOD){
            
            int tam = horrorIndex[a] + 1;
            horrorIndex[a] = horrorIndex[b] + 1;
            horrorIndex[b] = tam;
            continue;
        }
    }

    //Output the final answer by loop-through the caculated horrorIndex array

    int ans = 0, indexAns;

    for (int i = 0; i<=n-1; i++){

        if (horrorIndex[i] > ans){
            ans = horrorIndex[i];
            indexAns = i;
        }
    }

    cout << indexAns << '\n';

    // for (int i = 0; i<=n-1; i++) cout << horrorIndex[i] << " ";

        

        
}
