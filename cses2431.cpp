#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int q, n;
int numsDigits[20];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    numsDigits[1] = 9;

    for (int i = 2; i<=17; i++){
        numsDigits[i] = i * 9 * pow(10, i-1);
    }

    cin >> q;

    while (q--){
        cin >> n;

        int start = 1, currSum = 0;

        while (numsDigits[start] + currSum <= n) {
            currSum += numsDigits[start];
            start++;
        }

        start--;

        int currStart = pow(10, start);
        int remainingDigits = n - currStart;
        
        (if start != 0) int remainingNumbers = remainingDigits/start;
        int afterMod = remainingDigits%start;

        currStart += remainingNumbers;
        
        if (afterMod == 0) cout << currStart%10 << '\n';
        else {
            currStart++;
            string ans = to_string(currStart);
            cout << ans[afterMod - 1] << '\n';
        }





    }

    
}