#include <bits/stdc++.h>
using namespace std;

string studentName[3];
int studentScore[3];



int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }


    char c; cin >> c;

    int posOfC = c + 0;
    
    if (posOfC >=97 && posOfC <= 122) cout <<"YES"; else cout << "NO";

}

    