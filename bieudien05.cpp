#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;

struct Edge{
    int x,y,z;

    bool operator <(const Edge &e) const {
        return z < e.z;
    } 
};

Edge A[N];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n, m; cin >> n >> m;

    for (int i = 1; i<=m; i++) cin >> A[i].x >> A[i].y >> A[i].z;

    sort (A + 1, A + 1 + m); //sort theo operator trong struct

    for (int u = 1; u<=m; u++) cout << A[u].x << " " << A[u].y << " " <<  A[u].z << '\n'; 




}
