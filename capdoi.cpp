#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int n, target;
map<int, int> itemFrequency;

int sum1toN(int n){
    return (n*(n+1))/2;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> target;

    int res = 0; 

    //Using map to count the nums of appearance 
    for (int i = 1; i<=n; i++) {
        
        int x; cin >> x; itemFrequency[x]++;
        
        int tempSum = target - x;
        
        if (tempSum != x) res += itemFrequency[tempSum];
    }

    //Multiple x = target/2 appears
    if ((target % 2 == 0) && (itemFrequency[target/2] > 0)) {
        
    int specialCase = itemFrequency[target/2];

    res += sum1toN(specialCase - 1);

    

    }


    cout << res;
}