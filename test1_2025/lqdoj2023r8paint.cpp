#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define ll long long
const int N = 1e6 + 5;
ll n, a, b;
ll A[N];

bool isGood(long long w) {
    int usedA = 0, usedB = 0;
    long long cover = -1;
    for (int i=1;i<=n;i++) {
        if (A[i] <= cover) continue; // đã phủ
        // cần dùng 1 cọ mới
        if (usedB < b) {
            // thử dùng 2w trước
            usedB++;
            cover = A[i] + 2*w - 1;
        } else if (usedA < a) {
            usedA++;
            cover = A[i] + w - 1;
        } else return false;
    }
    return true;
}

ll sub3() {
    ll left = 1, right = (ll) 1e9;

    while (left <= right) {
        int mid = (left + right)/2;
        
        if (!isGood(mid -1) && isGood(mid)) return mid;
        if (isGood(mid -1) && isGood(mid)) right = mid - 1;
        else left = mid + 1;
    }

    return 1;
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("paint.inp", "r")) {
        freopen("paint.inp", "r", stdin);
        freopen("paint.out", "w", stdout);
    }

    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++) cin >> A[i];

    ll diff = 0;

    sort(A + 1, A + 1 + n);

    for (int i = 2; i <= n; i++) {
        cin >> A[i];
        diff = max(diff, A[i] - A[i - 1]);
    }

    if (n == 1) diff = 1;

    if (diff <= 1) cout << sub1();
    if (b == 0) cout << sub2();
    else sub3();

}