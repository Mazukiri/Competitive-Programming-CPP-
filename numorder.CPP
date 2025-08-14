#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long A[N];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n, m; cin >> n >> m;
    int index = 0;

    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++) {
            index++;
            A[index] = i*i + j*j;
        }
    }
    

}