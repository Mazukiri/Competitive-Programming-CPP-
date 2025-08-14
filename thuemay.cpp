#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;


struct Customer{
    int start;
    int end;
    int money;
};

Customer A[N];
vector<int> dp(N);

bool cmp(Customer a, Customer b){
    return a.end < b.end;
}

bool check(Customer a, Customer b){

    return (a.start >= b.end);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    for (int i = 1; i<=n; i++) cin >> A[i].start >> A[i].end >> A[i].money;

    sort(A + 1, A + 1 + n, cmp);

    for (int i = 1; i<=n; i++) dp[i] = A[i].money;

    for (int i = 2; i<=n; i++){

        for (int j = 1; j<i; j++) {
            if (check(A[i], A[j])) dp[i] = max(dp[i], dp[j] + A[i].money);
        }
    }

    int ans = 1;

    for (int i = 1; i<=n; i++) ans = max(ans, dp[i]);

    cout << ans;


}