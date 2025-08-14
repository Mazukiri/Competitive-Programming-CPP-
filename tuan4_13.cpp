#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n){

    string NtoString = to_string(n);
    string ans = "";

    for (int i = 0; i<NtoString.size(); i++) ans = NtoString[i] + ans;

    if (ans == NtoString) return true;
    return false;
}

bool isContains6(int n){
    int count_6 = 0;

    while (n>0){
        int digit = n%10;
        if (digit == 6) return true;
        n = n/10;
    }

    return false;
}

bool isSumEndWith8(int n){
    
    int sum = 0;
    while (n>0){
        sum += (n%10);
        n = n/10;
    }

    int digit = sum%10;

    if (digit == 8) return true;
    return false;

}

bool check(int n){
    if (isContains6(n) && isSumEndWith8(n) && isPalindrome(n)) return true;
    return false;
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int l, r; cin >> l >> r;

    for (int i = l; i<=r; i++) if (check(i)) cout << i << " ";
    
    
}