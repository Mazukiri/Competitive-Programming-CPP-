#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
int n, k;
int dp[N], A[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> k;

    for (int j = 1; j <= n; j++) cin >> A[j];

    int lost = 0, win = 1;


    for (int j = 1; j <= k; j++) {
        dp[j] = lost;

        for (int i = 1; i <= n; i++) {
            if (j >= A[i] && dp[j - A[i]] == lost) dp[j] = win;  
        }
    }

    if (dp[k] == win) cout << "First";
    else cout << "Second"; 

    
}