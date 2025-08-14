#include <bits/stdc++.h>
using namespace std;

long long A[1000005];

int BS(int left, int right, long long value, long long target){
    
    while (left <= right) {
        int mid = (left + right)/2;

        if (A[mid] + value == target) return mid;
        if (A[mid] + value < target) left = mid + 1;
        else right = mid - 1;

    }

    return -1;
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    long long n, target; cin >> n >> target;

    for (int i = 1; i<=n; i++) cin >> A[i];

    sort(A + 1, A + 1 + n);
    
    for (int i = 1; i<=n; i++){
        
        int index = BS(i+1, n, A[i], target);
        
        if (index == -1) continue;
        cout << i << " " << index;
        return 0;
    }

    cout <<"No solution";
    
}