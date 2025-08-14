#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;

int n,x;
int A[N];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> x;
    
    for(int i = 1; i <= n; i++) cin >> A[i];

    int index1 = 1;
    int index2 = 2;
    int index3 = 3;

    int ans = 0;

    for (int i = 1; i<=n-2; i++)
    for (int j = i + 1; j<=n-1; j++)
    for (int k = j + 1; k<=n; k++) ans++;

    cout << ans;
    

    // cout << "IMPOSSIBLE";

}
