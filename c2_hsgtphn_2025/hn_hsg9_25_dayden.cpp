#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int n, m, q, k;
const int N = 1e6 + 5;
int colors[4 * N];

void sub1() {

    char colors [N];

    for (int i = 1; i <= n; i++) colors[i] = 'V';

    for (int i = 1; i <= m; i++) {
        int x; cin >> x;

        //Change colors
        int from = x - k; 
        int to = x + k;

        for (int index = from; index <= to; index++) {
            if (colors[index] == 'V') colors[index] = 'D';
            else colors[index] = 'V';
        }
    }

    for (int i = 1; i <= q; i++) {
        int bulb; cin >> bulb;
        cout << colors[bulb] << '\n';
    }
}

void sub2() {
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        
        int left = x - k;
        int right = x + k;

        colors[left] += 1;
        colors[right + 1] -= 1;
    }

    // for (int i = 1; i <=n; i++) cout << colors[i] << " ";
    // cout << '\n';

    //prefix: if colors[index] % 2 == 0, it outputs "V" and "D" otherwise
    for (int i = 2; i <=n; i++) colors[i] += colors[i - 1];

    // for (int i = 1; i <=n; i++) cout << colors[i] << " ";
    // cout << '\n';

    //output
    for (int index = 1; index <= q; index++) {
        int i; cin >> i;
        // cout << colors[i] << " ";
        if (colors[i] % 2 == 0) {
            cout << 'V' << '\n';
        }
        else cout << 'D' << '\n';
    }

}

void sub3() {

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("dayden.inp", "r")) {
        freopen("dayden.inp", "r", stdin);
        freopen("dayden.out", "w", stdout);
    }

    cin >> n >> m >> q >> k;

    sub2();
}