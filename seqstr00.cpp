#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k;
vector<int> a[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> k;

    for (int i = 1; i<=n; i++) {
        string x; cin >> x;
        a[x.size()].push_back(i);
    }
    
    int res = 0;

    for (int s = 2; s<=22; s++) {
        for (int l = 0, r = 0; r<a[s].size(); r++)
            {
                //r = 3, l = 1
                while (a[s][r] - a[s][l] > k) l++;
                res += (r - l);
            }
    }

    int l  = 0;

    for (int r = 0; r<6; r++){
        while (a[r] - a[l] > k) l++;  //r - (l + 1)
        //r = 9, l = 6
        res += (r-l);
        //res = 1 + 2 + 3 + 3 + 3 + 3 + 3 + 3 + 3
    }

    cout << res;

}