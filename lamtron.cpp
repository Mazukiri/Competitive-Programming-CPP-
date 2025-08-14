#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    //Casting and Round

    long long a, b, c, d, e; cin >> a >> b >> c >> d >> e;

    long long largestCurrency = max(a,b);
    largestCurrency = max(largestCurrency, c);
    largestCurrency = max(largestCurrency, d);
    largestCurrency = max(largestCurrency, e);

    cout << "Dong lon nhat la: " << largestCurrency << '\n';

    long long ansCurrency = min(min(min(min(a,b), c), d), e); //Lay ra dong nho nhat trong 5 dong a, b, c, d, e

    cout << "Dong nho nhat la: " << ansCurrency << '\n';

    if ((ansCurrency < a) && (a<largestCurrency)) ansCurrency = a;
    if ((ansCurrency < b) && (b<largestCurrency)) ansCurrency = b;
    if ((ansCurrency < c) && (c<largestCurrency)) ansCurrency = c;
    if ((ansCurrency < d) && (d<largestCurrency)) ansCurrency = d;
    if ((ansCurrency < e) && (e <largestCurrency)) ansCurrency = e;

    cout << "Dong lon thu 2 la: " << ansCurrency;

    


    


}