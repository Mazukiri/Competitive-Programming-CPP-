#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m; 
int A[N], B[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 1; i<=n; i++) cin >> A[i];
    for (int i = 1; i<=m; i++) cin >> B[i];

    sort(A + 1, A + n + 1, greater<int>());
    sort(B + 1, B + m + 1, greater<int>());

    //Mang A la luu cac ban nam, B la cac ban nu
    //index1 la de tro vao mang cac ban nam, index2 la de tro vao mang cac ban nu
    int index1 = 1;
    int index2 = 1;
    int countPairs = 0;

    while (index1 <= n && index2 <= m){

        while (A[index1] > B[index2] && index2 <= m){
            countPairs++;
            index1++;
            index2++;
        }

        index2++;
    }

    cout << countPairs;
}