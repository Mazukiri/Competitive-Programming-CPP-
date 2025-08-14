#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int M, N, D, K;
char A[1000005];
int countMarkets[1000005];


void update(int x, int y){

}


void sub1_2(){

    for (int i = 1; i<=N; i++) {
        if (A[i] == 'M') {
            int left = max(i - D, (long long) 1);
            int right = min (N, i + D);
            
            for (int i = left; i<=right; i++) countMarkets[i]++;
        }
    }

    

    int ans = 0;

    for (int i = 1; i<=N; i++) if (A[i] == 'P' && countMarkets[i] >= K) ans++;

    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> M >> N >> D >> K;

    for (int i = 1; i<=N; i++) cin >> A[i];
    sub1_2();

}