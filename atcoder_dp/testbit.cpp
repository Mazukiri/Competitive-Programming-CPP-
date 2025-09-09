#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    short int decimal_number = 1;

    bitset<32> binary_representation(decimal_number);
    
    for (int i = 0; i < 8; i++) {
        int currNumber = (decimal_number << i);
        bitset<32> binary_representation(currNumber);
        cout << currNumber << " " << binary_representation << '\n';
    }
}