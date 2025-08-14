#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const long long N = 1e6+5;

int n; int A[N], B[N];

bool f(int t){
    //Return whether t seconds satifies

    for (int i = 1; i<=n; i++) A[i] = B[i];

    A[1] = A[1] - t;

    for (int i = 2; i<=n; i++) //Reschedule the ith ants
    {

        //A[i] < A[i-1]: Bat buoc phai dich A[i] sang phai cho toi khi cach A[i-1] + 1 don vi
        //A[i] > A[i-1]: Di sang trai nhieu nhat co the sao cho A[i] - steps < A[i-1] (steps <= t)
        
        if (A[i] < A[i-1]){

            int dist = A[i-1] + 1 - A[i];
            if (dist <= t) A[i] = A[i-1] + 1;
            //Khong the di chuyen toi duoc
            else {
                return false;
            }
        }

        else {
            if (A[i] == A[i-1]) {
              A[i]++;  
              if (t== 0) return false;
            }  
            
            else {
                A[i] = max(A[i-1] + 1, A[i] - t);
            }
            
        }

    }

    return true;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    for (int i = 1; i<=n; i++) cin >> B[i];

    /*while (cin >> a) {
        A[i] = a;
        i++;

        Chi dung cho nhap xuat file
    }*/

    int l = 0;
    int r = 1e18;
    int ans = 0;

    while (l<=r){
        int mid = (l+r)/2; //mid is t secs

        if (f(mid)) {
            ans = mid;
            r = mid - 1;
        }

        else l = mid + 1;
    }

    f(ans);
    cout << ans << '\n';
    for (int i = 1; i<=n; i++) cout << A[i] << " ";


}