#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, q;
int A[20];

void add(int value, int pos){
    for (int i = pos+1; i<=n + 1; i++) A[i] = A[i-1];
    A[pos] = value;
    n++;
}

void deletePos(int pos){
    for (int i = pos; i<= n-1; i++) A[i] = A[i + 1];
    n--;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> q;

    for (int i = 1; i<=n; i++) cin >> A[i];

    for (int i = 1; i<=q; i++) {

        int req; cin >> req;

        if (req == 1) {
            int pos, number; cin >> pos >> number;
            add(number, pos);
        }

        if (req == 2){
            int pos; cin >> pos;
            deletePos(pos);
        }

        else {
            int pos; cin >> pos;
            cout << A[pos] << '\n';
        }
    }
} 