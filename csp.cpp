#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int n, m;
const int N = 1e6 + 5;
int A[N];

int bs(int index){
    
    int left = index + 1, right = n;

    while (left <= right){

        int mid = (left + right)/2;
        
        if ((A[index] + A[mid] <= m) && (A[index] + A[mid+1] > m)) return mid;
        if (A[index] + A[mid] <= m) left = mid + 1; 
        else right = mid - 1;
    }

    return index;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 1; i<=n; i++) cin >> A[i];
    sort(A + 1, A + 1 + n);
    A[n+1] = m + 1;

    int ans = 0;

    for (int i = 1; i<=n; i++) {

        int ansIndex = bs(i);
        ans += (ansIndex - i);
    }

    cout << ans;
    
}