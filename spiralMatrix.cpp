#include <bits/stdc++.h>
using namespace std;

bool isTriangle(int a, int b, int c){
    return (a+b>c && a+c>b && b+c>a);
}

bool isRight(int a, int b, int c){
    return (a*a + b*b == c*c
            || a*a + c*c == b*b
            || b*b + c*c == a*a);
}

bool isEquilateral(int a, int b, int c){
    return ((a==b) && (b==c));
}

bool isIsoceles(int a, int b, int c){
    return (a==b) || (b==c); 
}


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("dp.inp", "r")) {
        freopen("dp.inp", "r", stdin);
        freopen("dp.out", "w", stdout);
    }

    int a, b, c; cin >> a >> b >> c;

    if (isTriangle(a, b, c)){

        if ((isEquilateral(a, b, c) && isRight(a,b,c))) {
            cout << 5;
            return 0;
            }
        if (isEquilateral(a,b,c)) cout << 4;
        if (isRight(a,b,c)) cout << 3;
        if (isIsoceles(a, b, c)) cout << 2;
    }

    cout << 0;


    
}