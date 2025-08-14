#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, target; 
int A[N];

int sum1toN(int n){
    return n*(n+1)/2;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> target;

    for (int i = 1; i<=n; i++) cin >> A[i];

    sort(A + 1, A + 1 + n);

    int index1 = 1, index2 = n; int ans = 0;

    while (index1 < index2){

        if ((A[index1] + A[index2] == target) && (target%2 == 0) && (A[index1] == target/2)){
            
            int left = 1;

            while (A[index1] == A[index1 + 1]) {
                left++;
                index1++;
            }

            ans += sum1toN(left-1);
            cout << ans;
            return 0;

        }

        if (A[index1] + A[index2] == target){
            
            int left = 1;
            int right = 1;

            while (A[index1] == A[index1 + 1] ) {
                left++;
                index1++;
            }

            while (A[index2] == A[index2 - 1] ) {
                right++;
                index2--;
            }

            ans += (left * right);

            index1++;
            index2--;

            continue;
        }

        if (A[index1] + A[index2] < target) index1++; else index2--;
    }

    cout << ans;
}