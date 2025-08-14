#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int n;
int A[N]; 

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i<=n; i++) {
        cin >> A[i];
        A[i] += A[i-1];
    }

    int l = 1, r = n;
    int ans = A[n];

    while (l <= r) {
        int mid = (l+r)/2;
        int bag1 = A[mid] - A[0];
        int bag2 = A[n] - A[mid];

        if (abs(bag1 - bag2) < ans) {
            ans = abs(bag1 - bag2);
        }

        if (bag2 > bag1) {
            l = mid + 1;
        } 

        else r = mid -1;
    }

    cout << ans;


    
}