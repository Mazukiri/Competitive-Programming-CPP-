#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 5;
int n, q;
int A[N], K[N];
int prefix[N], min_pre[N], min_pre_index[N];

void sub1() {
    // Tính prefix sum và min_pre
    prefix[0] = 0;
    min_pre[0] = 0;

    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + A[i];
        min_pre[i] = min(min_pre[i - 1], prefix[i - 1]);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans = max(ans, prefix[i] - min_pre[i]);
    }

    cout << ans << endl;
}

void sub2() {
    // Tính prefix sum
    prefix[0] = 0;
    min_pre[0] = 0;

    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + A[i];
        if (prefix[i] < min_pre[i-1]) {
            min_pre[i] = prefix[i];
            min_pre_index[i] = i;
        }

        else {
            min_pre[i] = min_pre[i-1];
            if (i != 1) min_pre_index[i] = min_pre_index[i-1];
            else {
                min_pre_index[i] = 1;
            }
        }

    }

    int maxsum1 = 0;
    int start, end;

    for (int i = 1; i <= n; i++) {
        if (prefix[i] - min_pre[i] > maxsum1) {
            maxsum1 = prefix[i] - min_pre[i];
            start = min_pre_index[i];
            end = i;
    }

    //Re-built new prefix_sum from end + 1 to n
    int new_prefix[n - end + 5];
    int new_min_pre[n - end + 5];

    for (int i = end + 1; i<=n; i++) {
        new_prefix[i] = new_prefix[i-1] + A[i];
        if (new_min_pre[i] > new_prefix[i]) {

        }


}




signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    if (fopen("TROCHOI.inp", "r")) {
        freopen("TROCHOI.inp", "r", stdin);
        freopen("TROCHOI.out", "w", stdout);
    }

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= q; i++) cin >> K[i];

    if (K[1] == 2 && q == 1) sub2();
    else sub1();
}
