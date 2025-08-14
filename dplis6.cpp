#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

template<class X, class Y> bool maxi(X& x, const Y y) {
    if (x < y) return x = y, 1;
    return 0;
}

const int N = 1e5+5;
int n, a[N];
int dp[N][2];
int trace[N][2];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    /*
    dp[i][0]: độ dài dãy đổi dấu max, khi lấy kết thúc tại a[i] mà trước đó là một số nhỏ hơn
    dp[i][1]: độ dài dãy đổi dấu max, khi lấy kết thúc tại a[i] mà trước đó là một số lớn hơn
    */

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int ans = 0, pos, state;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 1; // a1 > a2 < a3 ...
        dp[i][1] = 1; // a1 < a2 > a3 ...
        for (int j = 1; j < i; ++j) {
            if (a[j] < a[i]) {
                if (maxi(dp[i][1], dp[j][0] + 1))
                    trace[i][1] = j;
            }
            if (a[j] > a[i]) {
                if (maxi(dp[i][0], dp[j][1] + 1))
                    trace[i][0] = j;
            }
        }
        if (maxi(ans, dp[i][0]))
            pos = i, state = 0;

        if (maxi(ans, dp[i][1]))
            pos = i, state = 1;
    }
    cout << ans << '\n';
    vector<int> tr;
    tr.push_back(pos);
    while (trace[pos][state] != 0) {
        pos = trace[pos][state];
        state ^= 1; // đảo bit, hoán đổi trạng thái state từ 1-> 0 và 0->1
        tr.push_back(pos);
    }
    reverse(tr.begin(), tr.end());
    for (int i: tr) cout << a[i] << ' ';
    return 0;
}
