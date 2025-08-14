#include <bits/stdc++.h>
using namespace std;
const long long N = 1e7+5;
long long A[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   
    string n; cin >> n;
    
    string ans = "";
    
    long long dem_0 = 0;
    long long sumOfDigits = 0;
    
    for(int i = 0; i < n.size(); i++)
    {
        if(n[i] == '0')
        {
            A[i] = 0;
            dem_0++;
        }

        if(n[i] == '1') A[i] = 1;
        if(n[i] == '2') A[i] = 2;
        if(n[i] == '3') A[i] = 3;
        if(n[i] == '4') A[i] = 4;
        if(n[i] == '5') A[i] = 5;
        if(n[i] == '6') A[i] = 6;
        if(n[i] == '7') A[i] = 7;
        if(n[i] == '8') A[i] = 8;
        if(n[i] == '9') A[i] = 9;
        
        sumOfDigits += A[i];
    }


    sort(A, A + n.size());
    
    if(dem_0  == 0)
    {
        cout << "-1";
        return 0;
    }

    if(sumOfDigits % 3 != 0){
        cout << "-1";
        return 0;
    }


    for(int i = n.size()-1; i >= 0; i--)
    {
        if(A[i] == 0) ans += '0';
        if(A[i] == 1) ans += '1';
        if(A[i] == 2) ans += '2';
        if(A[i] == 3) ans += '3';
        if(A[i] == 4) ans += '4';
        if(A[i] == 5) ans += '5';
        if(A[i] == 6) ans += '6';
        if(A[i] == 7) ans += '7';
        if(A[i] == 8) ans += '8';
        if(A[i] == 9) ans += '9';
    }
    
    cout << ans;
}