#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const long long N = 1e6 + 5;
int n, t;
int A[N], prefixA[N];

int bs(int index){
    int l = index;
    int r = n;

    while (l<=r) {
        int mid = (l+r)/2;
        if ((prefixA[mid] - prefixA[index-1] <= t) && (prefixA[mid+1] - prefixA[index-1] > t)) return (mid - index + 1);
        if (prefixA[mid] - prefixA[index-1] <= t) l = mid + 1;
        else r = mid - 1;
    }

    return -1;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> t;
    
    for (int i = 1; i<=n; i++) cin >> A[i];
    
    for (int i = 1; i<=n; i++) prefixA[i] = prefixA[i-1] + A[i];

    int ans = 0;

    for (int i = 1; i<=n; i++) {
        int temp = bs(i);
        ans = max(temp, ans);
    }

    cout << ans;


}