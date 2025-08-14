#include <bits/stdc++.h>
using namespace std;

long long sumXtoY(long long l, long long r){
    
    long long ans = (l+r);
    ans *= (r-l+1);
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

    

    int l, r; cin >> l >> r;

    //khoi tao dap an
    long long finalDiff = (l+r)*(r-l+1)/2;
    finalDiff++;
    long long ans;

    for (int i = (l+r)/2; i<=r; i++){

        //Khoi tao tong va m
        long long tongL = 0;
        long long tongR = 0;
        int m = i;

        //Cong i vao tongL neu i<=m, Cong i vao tongR neu i>=m+1
        tongL = sumXtoY(l, m);
        tongR = sumXtoY(m+1, r);

        //cout << tongL << " " << tongR << '\n';

        //tim chech lech cua tongL va tongR
        long long diff = abs(tongL - tongR);

        //So sanh chech lech nay voi dap an hien co
        ///Neu chech lech nay nho hon dap an hien co,
        //Ta gan vi tri can tim la m, va diff moi la chech lech vua tinh
        if (diff < finalDiff) {
            
            finalDiff = diff;
            ans = m;
        }
    }

    cout << ans;
    
}