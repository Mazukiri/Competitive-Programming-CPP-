#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second
const int N = 1e6 + 5;
int n;
II A[N];
vector<int> dp(N, 1);
//dp[i]: Số cuộc họp nhiều nhất có thể tổ chức tới cuộc họp thứ i

bool cmp(II a, II b){
    return a.se < b.se;
}

bool check(II a, II b){
    return (b.se <= a.fi);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> A[i].fi >> A[i].se;

    sort(A + 1, A + 1 + n, cmp);

    for (int i = 1; i <= n; i++) cout << A[i].fi << " " << A[i].se << '\n';

    for (int i = 1; i<=n; i++){
        for (int j = 1; j<i; j++){

            if (check(A[i], A[j])) dp[i] = max(dp[j] + 1, dp[i]);
        }
    }

    int ans = 1;

    for (int i = 1; i<=n; i++) ans = max(ans, dp[i]);

    cout << ans;

    // 
    
    
}