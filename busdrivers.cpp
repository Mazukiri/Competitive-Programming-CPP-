#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n, d, r;
    
    while ((cin >> n >> d >> r && n != 0 && d != 0 && r != 0)){

    vector<int> a(n), b(n);    


    for(int i=0; i< n; i++) cin>> a[i];
    for(int i=0; i< n; i++) cin>> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    int sum = 0;
    
    for(int i=0; i< n; i++)
    {
        int total = a[i] + b[i];
        if (total > d){
            sum += (total-d)*r;
        }    
    }

    cout << sum << '\n';

    }

}