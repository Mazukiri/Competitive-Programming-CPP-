#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n;
int A[N];
bool existed[N];
int dp[N];
//dp[x]: Là phần dư tối thiểu khi xét i phần tử đầu tiên mà chênh lệch giữa hai người là x

void sub3() {
    int sumOfAllElements = 0;
    
    for (int i = 1; i<=n; i++) {
        sumOfAllElements += A[i];
    }

    dp[0] = 1;

    for (int i = 1; i<=n; i++) {
        for (int currSum = sumOfAllElements; currSum >= A[i]; currSum--) 
            dp[currSum] += dp[currSum - A[i]];
    }

    //for (int i = 1; i<=sumOfAllElements; i++) cout << i << " " << dp[i] << '\n';
    //cout << '\n';

    int ans = 1;

    for (int i = 1; i<=sumOfAllElements / 2; i++) 
        if (dp[i] >= 2 && dp[sumOfAllElements - 2*i] > 0) ans = i;

    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("CT.inp", "r")) { 
        freopen("CT.inp", "r", stdin);
        freopen("CT.out", "w", stdout);
    }

    cin >> n;
    
    for (int i = 1; i <=n; i++) cin >> A[i];

    // if (n <= 3) cout << sub1();
    // else cout << 0;

    sub3();
}