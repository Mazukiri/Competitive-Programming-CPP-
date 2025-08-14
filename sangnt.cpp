#include <bits/stdc++.h>
using namespace std;
bool F[1000001];
int GreatestPrimeFactor[1000001];

/*void SangNTTrueFalse(){ //Sang True/False
    //F[i] = True --> i la so nguyen to
    //F[i] = False --> i khong la so nguyen to
    for (int i = 1; i<=1000000; i++) F[i] = true;
    for (int i = 2; i<=1000000; i++){ 
        //Neu I la so nguyen to
        if (F[i]) for (int j = 2; j<=1000000/i; j++) F[i*j] = false; 
    }
}*/

void SangNTTheoUoc(){
    //GreatestFactor[i] = Thua so nguyen to lon nhat cua so i
    for (int i = 2; i<=1000000; i++) GreatestPrimeFactor[i] = i;
    for (int i = 2; i<=1000000; i++){
        if (GreatestPrimeFactor[i] == i) for (int j = 2; j<=1000000/i; j++) GreatestPrimeFactor[i*j] = i;
    }
}
    

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("dp.inp", "r")) {
        freopen("dp.inp", "r", stdin);
        freopen("dp.out", "w", stdout);
    }

    // isPrime(n)?
    //O(N), O(N^2), O(logN), ...

    int n; cin >> n;

    SangNTTheoUoc();

    while (n!=1){
        int divisor = GreatestPrimeFactor[n];
        cout << divisor << " * ";
        n = n/divisor;
    } 

    //60 = 2^2 * 3^ 5;
    // (2^3 - 1/2 - 1) * (3^2 - 1/3-1) * (5^2 - 1/ 5 -1) = 7 * 4 * 6 = 168 
}