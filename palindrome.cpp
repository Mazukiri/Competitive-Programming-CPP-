#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
const int N = 1e6 + 5;
string s1, s2;
int vitri[1000];

signed main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> s1 >> s2;

    int index = 0, dem = 0;

    for (int i = 0; i + s1.size() - 1 < s2.size(); i++){

        string sub_string = s2.substr(i, s1.size());

        if (sub_string == s1) {
            dem++;
            index++;
            vitri[index] = i;
        }
    }

    cout << dem << '\n';

    for (int i = 1; i<=index; i++) cout << vitri[i] << " "; 
    

    
}