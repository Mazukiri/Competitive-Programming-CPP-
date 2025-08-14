#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e5 + 5;
int countU[N], countI[N];

string s, t;

bool check(int l, int r){
    
    int cU = countU[r] - countU[l - 1];
    int cI = countI[r] - countI[l - 1];

    if (cI >= cU * 2 && cU > 0 && cI > 0) return true;
    if (cU >= cI * 2 && cU > 0 && cI > 0) return true;
    return false;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int q; cin >> q;

    for (int _ = 1; _ <=q; _++) {
        cin >> s;

        bool flag = false;
  
        for (int i = 0; i<s.size() + 5; i++) {
            countU[i] = 0;
            countI[i] = 0;
        }

        if (s[0] == 'U') countU[1]++; 
        else countI[1]++;

        for (int i = 1; i<s.length(); i++) {
            if (s[i] == 'U') countU[i + 1]++;
            countU[i + 1] += countU[i];
            if (s[i] == 'I') countI[i + 1]++;
            countI[i + 1] += countI[i];
        }

        for (int i = 0; i<s.size() - 1; i++) {
           
            for (int j = i + 1; j<s.size(); j++) {
                if (check(i + 1, j + 1)) {
                    cout << "YES" << " " << i + 1 << " " << j + 1 << '\n';
                    flag = true;
                    break;
                }
            }

            if (flag) break;
        }

        if (!flag) cout << "NO" << '\n';
    }
}