#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int A[N];
int n, leftLimit, rightLimit;

bool isValid(int curr) {
    if (curr >= leftLimit && curr <= rightLimit) return true;
    return false;
}

void sub1() {
    
    int ans = 1000000000000 ;

    for (int i = 1; i<=n-1; i++) {
        int currSum = 0;
        
        for (int j = i + 1; j<=n; j++) {
            currSum = A[i] + A[j];
            if (isValid(currSum)) ans = min(ans, currSum);
        }
    }

    cout << ans;
}

int bs(int l, int r, int firstItem) {

    int ans = 1000000000000000000;

    while (l <= r) {
        int mid = (l+r)/2;
        
        if (firstItem + A[mid] < leftLimit) {
            l = mid + 1;
        }

        if (firstItem + A[mid] > rightLimit) {
            r = mid - 1;
        }

        if (isValid(firstItem + A[mid])) {
            ans = min(ans, A[mid]);
            r = mid - 1;
        }
    }

    return ans;
}

void sub2(){

    int ans = 1000000000000 ;

    for (int i = 1; i<=n; i++) {
        int currSum = A[i];
        int secondItem = bs(i + 1, n, A[i]);
        if (secondItem != 1000000000000000000) {
            //Ton tai secondItem sao cho l <= A[i] + secondItem <= r
            currSum += secondItem;
            ans = min(ans, currSum);
        }
    }

    cout << ans;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("MUASAM.inp", "r")) {
        freopen("MUASAM.inp", "r", stdin);
        freopen("MUASAM.out", "w", stdout);
    }

    cin >> n >> leftLimit >> rightLimit;
    for (int i = 1; i <= n; i++) cin >> A[i];
    
    sort(A + 1, A + n + 1);

    if (n<=1000) sub1();
    else sub2();
    
}