#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m; 
int A[N], B[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 1; i<=n; i++) cin >> A[i];
    for (int i = 1; i<=m; i++) cin >> B[i];

    int index1 = 1, index2 = 1; int ans = 0;

    while (index1 <= n && index2 <= m){

        if (A[index1] == B[index2]){
            
            int left = 1;
            int right = 1;

            while (A[index1] == A[index1 + 1] ) {
                left++;
                index1++;
            }

            while (B[index2] == B[index2 + 1] ) {
                right++;
                index2++;
            }

            ans += (left * right);
        }

        if (A[index1] < B[index2]) index1++; else index2++;
    }

    cout << ans;
}