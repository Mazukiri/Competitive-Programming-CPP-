#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int dp[N]; //Độ dài lớn nhất của dãy con kết thúc tại i
int A[N];
int n;


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n; 

    for (int i = 1; i<=n; i++) cin >> A[i];

    for (int i = 1; i<=n; i++) dp[i] = 1;


    //recurrent relation
    for (int i = 2; i<=n; i++){
        for (int j = 1; j<i; j++)

        //i = 4, j = 1

        if (A[j] < A[i]) dp[i] = max(dp[i], dp[j] + 1);
    }

    int ans = 0;

    for (int i = 1; i<=n; i++) ans = max(ans, dp[i]);

    cout << ans;
}