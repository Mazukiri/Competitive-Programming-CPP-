#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int n;
const int N = 1e6 + 5;
bool hasPrint[N];
vector<int> firstSeq, secondSeq;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    int sum = (n*(n+1))/2;

    if (sum % 2 != 0) {
        cout << "NO";
        return 0;
    }

    int currIndex = n, halfSum = sum/2;

    
    while (halfSum > 0){
        if (halfSum - currIndex > 0){
            firstSeq.push_back(currIndex);
            hasPrint[currIndex] = true;
            halfSum -= currIndex;
            currIndex--;
        }

        else {
            firstSeq.push_back(halfSum);
            hasPrint[halfSum] = true;
            halfSum = 0;
        }
    }

    for (int i = 1; i<=n; i++){
        if (!hasPrint[i]) secondSeq.push_back(i);
    }
    cout << "YES" << '\n';
    cout << firstSeq.size() << '\n';
    for (auto x: firstSeq) cout << x << " ";
    cout << '\n';
    cout << secondSeq.size() << '\n';
    for (auto x: secondSeq) cout << x << " ";


    
}