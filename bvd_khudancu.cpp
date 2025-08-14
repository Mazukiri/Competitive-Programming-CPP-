#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int M, N, D, K;
int countMarkets[3001][3001];
char A[3001][3001];

void update(int x, int y){

    //di len
    for (int index = 1; index<=D; index++) if (x - index >=0) countMarkets[x - index][y]++;
    //di xuong
    for (int index = 1; index<=D; index++) countMarkets[x + index][y]++;
    //di sang trai
    for (int index = 1; index<=D; index++) if (y - index >= 0)countMarkets[x][y - index]++;
    //di sang phai
    for (int index = 1; index<=D; index++) countMarkets[x][y + index]++;
    
    //di cheo phai tren
    for (int index = 1; index<=D; index++) countMarkets[x + index][y + index]++;
    //di cheo trai duoi 
    for (int index = 1; index<=D; index++) if (x - index >= 0 && y - index >= 0) countMarkets[x - index][y - index]++;
    //di cheo phai duoi
    for (int index = 1; index<=D; index++) if (y - index >= 0) countMarkets[x + index][y - index]++;
    //di cheo trai tren
    for (int index = 1; index<=D; index++) if (x - index >= 0) countMarkets[x - index][y+ index]++;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> M >> N >> D >> K;
    
    for (int i = 1; i<=M; i++){
        for (int j = 1; j<=N; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'M') update(i, j);
        }
    }

    int ans = 0;

    for (int i = 1; i<=M; i++){
        for (int j = 1; j<=N; j++){
            if (A[i][j] == 'P' && countMarkets[i][j] >= K) ans++;
        }
    }

    cout << ans;



    


}