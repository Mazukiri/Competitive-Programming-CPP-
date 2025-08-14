#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int L[N]; //L[i] = 0: Không thể tạo được tổng này. L[i] = 1: tạo được tổng này
int A[N];
int n;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    L[0] = 1;

    cin >> n; 

    int t = 0;

    for (int i = 1; i<=n; i++) {
        cin >> A[i];
        t += A[i];
    }

    //O(n * t) = 10^7
    for (int i = 1; i<=n; i++){
        for(int currentSum = t; currentSum >= A[i]; currentSum--){

            if (L[currentSum - A[i]] == 1) L[currentSum] = 1;
        }
    }

    int ans = 0;

    for (int i = 1; i<=t; i++) if (L[i]) ans++;
    
    cout << ans << '\n';

    for (int i = 1; i<=t; i++) {
        if (L[i]) cout << i << " ";
    }

    
}