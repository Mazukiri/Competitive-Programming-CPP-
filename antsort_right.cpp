#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;
int A[N], B[N];

bool f(int t){

    for (int i = 1; i<=n; i++) A[i] = B[i];

    A[1] = A[1] - t;

    //2 scenarios: 
    // A[i] > A[i-1]: max(A[i-1]+1, A[i] - t)
    // A[i] < A[i-1]: A[i] + t >= A[i-1] + 1 

    for (int i = 2; i<=n; i++){

        if (A[i] > A[i-1]) A[i] = max(A[i-1] + 1, A[i] - t);
        if (A[i] < A[i-1]){

            if (A[i] + t < A[i-1] + 1) return false;
            A[i] = A[i-1] + 1;
        }

        if (A[i] == A[i-1]){

            if (t==0) return false;
            A[i] = A[i-1]+1;
        }
    }

    return true;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    for (int i = 1; i<=n; i++) cin >> B[i];

    int l = 0, r = 1e18, ans = 0;

    while (l <= r){
        
        int mid = (l+r)/2;
        
        if (f(mid)) {
            ans = mid;
            r = mid - 1;
        }

        else l = mid + 1;
    }

    f(ans);

    cout << ans << '\n';
    for (int i = 1; i<=n; i++) cout << A[i] << " ";


}