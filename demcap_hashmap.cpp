#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int n, target;
vector<int> A;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> target;

    for (int i = 0; i<n; i++) {
        int x; cin >> x; A.push_back(x);
    }

    sort(A.begin(), A.end());

    unordered_map<int, int> freq;
    int count = 0;

    for (int num1: A){

        int num2 = target - num1;

        if (freq[num2] > 0) {
            count++;
            freq[num2]--;
        }

        else freq[num1]++;
    }

    cout << count;

        
}

