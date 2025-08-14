#include <bits/stdc++.h>
using namespace std;
long long dem[1000001]; //dem[i]: co bao nhieu lan gia tri i xuat hien trong mang


signed main()
{
    freopen("dp.inp","r",stdin);
    freopen("dp.out","w",stdout);

    int n; cin >> n;
    long long A[n];
    
    for (int i = 1; i<=1000000; i++) dem[i] = 0; //Khởi tạo số lần xuất hiện của các phần tử trong mảng

    for (int i = 1; i<=n; i++) {
        cin >> A[i];
        dem[A[i]]++; //tăng số lần xuất hiện của A[i] trong mảng
    }

    //Q truy van, moi truy van in ra so lan xuat hien cua x
    long long q; cin >> q;
    
    for (int i = 1; i<=q; i++){
        
        long long x; cin >> x;
        cout << dem[x] << '\n';
    }

}
