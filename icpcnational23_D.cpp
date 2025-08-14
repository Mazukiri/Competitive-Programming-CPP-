#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;
int cnt[N], A[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int t; cin >> t;

    
    while (t--){

        cin >> n; 
        
        for (int i = 1; i<=n; i++) cin >> A[i];

        int ans = 0, j = 0; 

        for (int i = 1; i<=n; i++) cnt[A[i]] = 0;

        for (int i = 1; i<=n; i++){

            while (j + 1 <= n && cnt[A[j + 1]] == 0) {
                j++;
                cnt[A[j]] = 1;
            }

            ans += (j - i + 1);

            cnt[A[i]] = 0;
        }

        cout << ans << '\n';

    }

    

    

   



}

    


