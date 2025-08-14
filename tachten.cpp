#include <bits/stdc++.h>
using namespace std;

const long long N = 1e2 + 5;

int A[N][N][N]; //1e6

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int r, c; cin >> r >> c;

    for (int i = 1; i<=r; i++){
        for (int j = 1; j<=c; j++) cin >> A[i][j];
    }
    

    for (int i = 1; i<=r; i++){
        for (int j = 1; j<=c; j++) cout << A[i][j] << " ";
        cout << '\n';
    }

    
    
}