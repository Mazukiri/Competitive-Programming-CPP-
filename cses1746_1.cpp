#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, m, q;
int dp[N][105];
int A[N];

bool isValid(int potentialValue, int target, int steps) {
    return (potentialValue + steps + 1 >= target);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    A[0] = 0;

    for (int i = 1; i <=n; i++) cin >> A[i];

    int ans = 0;

    for (int i = 1; i <=n; i++) {
        if (A[i] != 0) continue;

        int left = i;

        while (A[i] == 0) i++;

        int right = i;

        if (A[left - 1] - 1 > 0 && isValid(A[left - 1] - 1, A[right], right - left - 1)) dp[left][min(0LL, A[left - 1] - 1)] = 1;
        
        if (A[left - 1]  > 0 && isValid(A[left - 1], A[right], right - left - 1)) dp[left][A[left - 1]] = 1;
        
        if (A[left - 1] + 1 > 0 && isValid(A[left - 1] + 1, A[right], right - left - 1)) dp[left][A[left - 1] + 1] = 1;

        for (int index = left + 1; index <= right; index++) {
            
            for (int value = 1; value <= m; value++) {
                
                if (isValid(value, A[right], right - index - 1)) {
                    dp[index][value] += dp[index - 1][value] 
                                        + dp[index - 1][value -1] 
                                        + dp[index - 1][value +1];
                }

                else {
                    dp[index][value] = dp[index - 1][value];
                }
            }
        }

        for (int value = 1; value <= m; value++) ans += dp[right - 1][value];
    }

    cout << ans; 
    

    
}