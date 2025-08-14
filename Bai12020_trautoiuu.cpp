#include <bits/stdc++.h>
using namespace std;
long long X, Y;

long long sumXtoY(long long X, long long Y){
    
    long long ans = X + Y;
    ans *= (Y-X+1);
    ans /= 2;

    return ans;
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("BAI1.inp", "r")) {
        freopen("BAI1.inp", "r", stdin);
        freopen("BAI1.out", "w", stdout);
    }

    
    cin >> X >> Y;
    long long ans = sumXtoY(X, Y);
    long long realAns;

    for (int i = ((X+Y)/2); i<=Y; i++){
        long long leftSum = sumXtoY(X, i);
        long long rightSum = sumXtoY(i+1, Y);
        if (abs(rightSum - leftSum) < ans){

            ans = abs(rightSum - leftSum);
            realAns = i;
        }
    }

    cout << realAns;
    
}