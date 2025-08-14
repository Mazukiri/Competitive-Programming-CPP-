#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
string ans;
string number;

string chuanhoa (string s){

    if (s[0] == '-' && s[1] == '0') {
        s.erase(0, 1);
        return s;
    }

    int isNegative = 0;

    if (s[0] == '-'){
        isNegative++;
        s.erase(0, 1);
    }

    while (s.size() > 1 && s[0] == '0') s.erase(0, 1);

    if (isNegative == 0) return s; 
    else{
       s = '-' + s;
       return s; 
    } 
}

bool sosanh(string a, string b){

    //return true so b > so a va nguoc lai

    if (ans.size() == 0) return true;

    if (a[0] == '-' && b[0] != '-') return true;
    if (a[0] != '-' && b[0] == '-') return false;

    if (a[0] == '-' && b[0] == '-'){
        
        if (a.size() < b.size()) return false;
        if (a.size() == b.size()){

        for (int i = 0; i<a.size(); i++){
            if (a[i] < b[i]) return false;
            if (a[i] > b[i]) return true;
        }
    }
    }

    
    if (a.size() < b.size()) return true;
    if (a.size() == b.size()){

        for (int i = 0; i<a.size(); i++){
            if (a[i] > b[i]) return false;
            if (a[i] < b[i]) return true;
        }
    }

    if (a == b) return true;

    return false;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    getline(cin, s);

    ans = "";
    number = "";

    for (int i = 0; i<s.size(); i++) {

        while (s[i] >= '0' && s[i] <= '9' || (s[i] == '-' && number.size() == 0)){
            number += s[i];
            i++;
        }

        number = chuanhoa(number);

        if (sosanh(ans, number)){
            ans = number;
        }

        number = "";
    } 

    ans = chuanhoa(ans);

    cout << ans;
}