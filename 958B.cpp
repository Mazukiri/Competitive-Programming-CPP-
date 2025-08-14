#include <bits/stdc++.h>
using namespace std;

void solve(string s){

    string ans = "";

    int k = 0;

    while (k<s.size()){
        
        if (s[k] == '1') {
            ans += '1'; 
            k++;
            continue;
        }

        else {
            while (s[k] == '0') k++;
            ans += '0';
            continue;
        }
    }

    //Sau khi xoa het so 0

    int c0 = 0, c1 = 0;

    for (int j = 0; j<ans.length(); j++){

        if (ans[j] == '1') c1++;
        if (ans[j] == '0') c0++;
    }

    if (c1 > c0) cout << "YES" << '\n'; else cout << "NO" << '\n';
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int t; cin >> t;

    for (int i = 1; i<=t; i++){
    
        int n; string s; 
        cin >> n >> s;
        
        solve(s);

    }

    
}