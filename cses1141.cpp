#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
map<int, int> freq;
int n;
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    int start = 1, end, ans = 1;

    for (int i = 1; i<=n; i++){

        int x; cin >> x;

        if (freq[x] == 0) {

            freq[x]++;
            end = i;
        }

        else {
            ans = max(ans, end - start + 1);
            start++;
        }
    }

    end = n;
    ans = max(ans, end - start + 1);

    cout << ans;
}
