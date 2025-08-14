#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const string NAME = "MAI HOANG DUC";


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    //Nhap xau
    string a, b, c; 

    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    
    cout << a << '\n' << b << '\n' << c << '\n';
    

    //Duyet xau: 0 -> length-1
    
    for (int i = 0; i<a.size(); i++){
        cout << a[i] << " ";
    }

    cout << '\n';

    a = "123";
    b = "4";

    /*a = a + b;
    cout << a << '\n';
    */

    //stoll(n): string to long long

    int x = stoi(a); //string to integer
    int y = stoi(b);

    cout << x + y << '\n';

    char d = '1';
    int e = 10;

    cout << d + e << '\n';
    
    //a = a + b; //Ghep xau b vao cuoi xau a
    
    a = "1";
    a.append("234");

    cout << a << '\n';

    //a.pop_back();
    

    //cout <<  a << '\n';

    //a.clear();

    cout << a << '\n';

    a = "abcd";
    b = "be";

    if (a.size()>b.length()) cout << a << '\n'; else cout << b << '\n';

    a = "edrw1qrfytu6g3eh45yikp,wm2j1o8rei9ok gvcjmlwr#E@ZAOI(03edrca)";
    sort(a.begin(), a.end());
    cout << a << '\n';

    a = "Chungtakhongthuocvenhau";
    
    //cout << a.substr(7, 21) << '\n';

    //cout << a;

    //a += b;
    //a = b + a;

    //  "1234"
    //string ans = "";
    //for (int i = 0; i<a.size(); i++){
        //ans = a[i] + ans;
    //}

    //cout << ans;







    

}