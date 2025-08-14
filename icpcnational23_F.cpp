#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
string s;
int countR[N], countP[N], countS[N];

void solve(){
    
    for (int i = 1; i<=s.size(); i++) {
        countR[i] = countR[i-1] + (s[i-1] == 'R');
        countS[i] = countS[i-1] + (s[i-1] == 'S');
        countP[i] = countP[i-1] + (s[i-1] == 'P');
    }

    int ans = 0, currentAns = 0;

    for (int k = 2; k<=s.size(); k++){

        int countTempAns = 0;

        for (int j = 1; j<=s.size(); j += k){

            int l = j, r = j + k  - 1;

            r = min(r, (int) s.size());

            int temp = 0;

            temp = max(temp, countR[r] - countR[l-1]);
            temp = max(temp, countP[r] - countP[l-1]);
            temp = max(temp, countS[r] - countS[l-1]);

            countTempAns += temp;
        }

        if (countTempAns >= currentAns) {
            currentAns = countTempAns;
            ans = k;
        }
    }

    cout << ans << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    //k * n/k = n

    int t; cin >> t;

    for (int i = 1; i<=t; i++){

        cin >> s;

        solve();
        
    }
}