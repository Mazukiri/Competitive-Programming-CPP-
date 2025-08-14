#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const long long N = 1e6 + 5;
int n, k; 
int A[N];

int bs (int index){
    
    int l = 1, r = n;

    while (l<=r){
        int mid = (l+r)/2;
        
        if ((A[mid] - A[index] <= k) && (A[mid+1] - A[index] > k)) return (mid-index+1);
        if ((A[mid] - A[index] <= k)) l = mid + 1; else r = mid - 1;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> k;

    for (int i = 1; i<=n; i++) {
        cin >> A[i];        
        if (A[i] > k) {
            cout << -1;
            return 0;
        }
    }

    //Prefixsum A[i] = A[i-1] + A[i]

    for (int i = 2; i<=n; i++) A[i] = A[i-1] + A[i];

    int ans = 0;

    for (int i = 1; i<=n; i++){
        int temp = bs(i);
        ans = max(ans, temp);
    }

    cout << ans;

    




}