#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second
set<int> primeN;
set<int> primeM;
vector<int> ans; 
map<int, int> cntN;
map<int, int> cntM;
int n, m;

bool isViolated(int n, int m) {
    if (n == 1 && m != 1) return true;
    if (n > m) return true;
    if (m % n != 0) return true;

    return false;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int q; cin >> q;

    for (int _ = 1; _ <= q; _++) {

        primeN.clear();
        primeM.clear();
        ans.clear();
        cntN.clear();
        cntM.clear();

        cin >> n >> m;
    
        if (isViolated(n, m)) {
            cout << -1 << '\n';
            continue;
        }

        if (n == m) {
            cout << 0 << '\n';
            continue;
        }

        

        int currN = n, currM = m;

        for (int i = 2; i<= ceil(sqrt(n)); i++) {
            while (currN % i == 0) {
                currN /= i;
                primeN.insert(i);
                cntN[i]++;
            }
        }

        if (currN != 1) {
            primeN.insert(currN);
            cntN[currN]++;
        }

        for (int i = 2; i<= ceil(sqrt(m)); i++) {
            while (currM % i == 0) {
                currM /= i;
                primeM.insert(i);
                cntM[i]++;
            }
        }

        if (currM != 1) {
            primeM.insert(currM);
            cntM[currM]++;
        }

        if (primeN.size() != primeM.size()) {
            cout << -1 << '\n';
            continue;
        }

        int sizee = primeM.size();

        for (auto x: primeM) {
            primeN.insert(x);
            
        }

        if (sizee != primeN.size()) {
            cout << -1 << '\n';
            continue;
        }

        bool flag = true;

        for (auto x: primeM) {
            if (cntN[x] > cntM[x]) {
                flag = false;    
            }
        }

        if (flag == false) {
            cout << - 1 << '\n';
            continue;
        }

        int nums = 0;

        while (n != m) {
            int times = min((m/n), n);
            ans.push_back(times);
            nums++;
            n *= times;
        }

        cout << nums << " ";

        for (int i = 0; i<ans.size(); i++) cout << ans[i] << " ";
        
        cout << '\n';
    }
}