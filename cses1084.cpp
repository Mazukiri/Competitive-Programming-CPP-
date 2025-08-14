#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, guests, variety;
const int N = 1e6 + 5;
int Area[N], desireArea[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> guests >> n >> variety;

    for (int i = 1; i <= guests; i++) cin >> desireArea[i];
    for (int i = 1; i <= n; i++) cin >> Area[i];

    sort(Area + 1, Area + n + 1, greater<int>());
    sort(desireArea + 1, desireArea + guests + 1, greater<int>());

    int index1 = 1, index2 = 1;
    int count = 0;

    while (index1 <= n && index2 <= guests) {
        if (abs(desireArea[index2] - Area[index1]) <= variety) {
            count++;
            index1++;
            index2++;
        } else {
            // Move to the next available area that might match the current desire
            if (Area[index1] > desireArea[index2]) {
                index1++;
            } else {
                index2++;
            }
        }
    }

    cout << count;
}
