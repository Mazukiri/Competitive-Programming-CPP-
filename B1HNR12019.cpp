#include <bits/stdc++.h>
using namespace std;

// Function to calculate the sum of integers from a to b
long long sumtoN(int a, int b){
    long long nums = abs(b - a) +1;
    long long ans = nums * (a+b);
    ans /= 2;
    return ans;
}

// Function to check the given conditions
bool check(int i, long long n){
    if (i % 2 == 1 && n % i == 0 && n >= sumtoN(1, i)) 
        return true;
    if (i % 2 == 0 && n % i == i/2 && n >= sumtoN(1, i)) 
        return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // File handling
    if (fopen("BAI1.inp", "r")) {
        freopen("BAI1.inp", "r", stdin);
        freopen("BAI1.out", "w", stdout);
    }

    long long n; cin >> n;
    long long ans = 0;
    
    // The correct limit should be ceil(sqrt(2*n))
    int limit = ceil(sqrt(2 * n));
    
    for (int i = 1; i <= limit; i++){
        if (check(i, n)) ans++;
    }

    cout << ans;
}
