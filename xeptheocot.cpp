#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
vector<int> matrixRowm [1000005];
int A[1001][1001];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n; cin >> n;
    

    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++){

            cin >> A[i][j];
        }
    }

    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++){

            matrixRowm[i].push_back(A[i][j]);
        }
    }
   
    int t; cin >> t;

    for (int i = 1; i<=t; i++) {
        int l, r; cin >> l >> r;
        swap(matrixRowm [l], matrixRowm [r]);
    }


    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++){

            A[i][j] = matrixRowm [i].at(matrixRowm[i].size() - i - 1);
            matrixRowm [i].pop_back();
        }

    }

    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++){

            cout << A[i][j] << " ";
        }

        cout << '\n';
    }

    
}