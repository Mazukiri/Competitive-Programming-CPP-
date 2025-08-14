#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;
int f[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    //An có n ghế đen, n ghế đỏ, n ghế trắng
    //Lấy ra một dãy n ghế. Tuy nhiên, không được xếp 2 ghế đỏ cạnh nhau
    //Hỏi có bao nhiêu cách lấy ra n ghế theo cách mà An muốn

    cin >> n;

    f[1] = 3;
    f[2] = 8;

    for (int i = 3; i<=n; i++){
        
        f[i] = 2 * (f[i - 1] + f[i - 2]);
    }

    cout << f[n];

    //Gọi f[i] là số cách xếp i cái ghế
    // Nếu cái ghế thứ i là ghế màu đen, thì sẽ có f[n-1] cách xếp
    // Nếu cái ghế thứ i là ghế màu trắng, thì sẽ có f[n-1] cách xếp
    // Nếu cái ghế thứ i ghế màu đỏ, thì 1 * 2 * f[n-2]
}