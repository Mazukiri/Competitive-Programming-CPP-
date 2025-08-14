#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int q;
string s;
const int N = 12;
int countU[N], countI[N];

bool check(int l, int r) {

    int cU = countU[r] - countU[l - 1];
    int cI = countI[r] - countU[l - 1];

    if (cU >= cI * 2 && cU > 0 && cI > 0) return true;
    if (cI >= cU * 2 && cU > 0 && cI > 0) return true;

    return false;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> q;
    
    for (int _ = 1; _ <= q; _++) {
        
        cin >> s;

        for (int i = 0; i<s.size(); i++) {
            countU[i] = 0;
            countI[i] = 0;
        }
 
        if (s[1] == 'U') countU[0]++;
        else countI[0]++;

        for (int i = 1; i<s.size(); i++) {
           
            if (s[i] == 'U') countU[i + 1]++;
            countU[i + 1] += countU[i];
            if (s[i] == 'I') countI[i + 1]++;
            countI[i + 1] += countI[i];
        }

        bool flag = false;

        for (int i = 1; i<s.length() - 1; i++) {
            
            for (int j = i + 1; j < s.length(); j++) {
            
                if (check(i, j))  {
                    cout << "YES" << " " << i + 1 << " " << j + 1 << '\n';
                    flag = true;
                    break;
                }
            }

            if (flag) break;
        }

        if (flag == false) cout << "NO" << '\n'; 
    }
}