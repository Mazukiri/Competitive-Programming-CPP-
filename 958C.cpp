#include <bits/stdc++.h>
using namespace std;

int n;

bool checkSumOR(int a, int b){

    int c = a|b;

    if (c == n) return true;
    return false;
}

void solve(){

    int bitwise_numbers[n+1];

    int x = n^(n-1);

    bitwise_numbers[0] = x;
    int count = 1;
    int i = 1;

    while (x != 0 && count<n) {
        if (checkSumOR(bitwise_numbers[i], x)){
            i++;
            bitwise_numbers[i] = x;
            count++;
        }
        x--;
    }

    cout << i+1 << '\n';
    for (int j = i; j>=0; j--) cout << bitwise_numbers[i] << " ";
    cout << '\n';
    
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
        
        cin >> n;
        solve();
    }
    
}