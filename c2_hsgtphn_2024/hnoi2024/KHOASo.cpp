#include <bits/stdc++.h>
using namespace std;
#define int long long

int xoaytrai(int target, int curr) {
    int step = 0;

    while (curr != target) {
        step++;
        if (curr == 0) curr = 9;
        else curr--;
    }

    return step;
}

int xoayphai(int target, int curr) {
    int step = 0;

    while (curr != target) {
        step++;
        if (curr == 9) curr = 0;
        else curr++;
    }

    return step;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("KHOASO.inp", "r")) {
        freopen("KHOASO.inp", "r", stdin);
        freopen("KHOASO.out", "w", stdout);
    }

    int A = 2;
    int B = 0;
    int C = 2;
    int D = 5;

    int currA, currB, currC, currD; 
    cin >> currA >> currB >> currC >> currD;

    int stepA, stepB, stepC, stepD;
    
    stepA = min(xoaytrai(A, currA), xoayphai(A, currA));
    stepB = min(xoaytrai(B, currB), xoayphai(B, currB));
    stepC = min(xoaytrai(C, currC), xoayphai(C, currC));
    stepD = min(xoaytrai(D, currD), xoayphai(D, currD));

    cout << stepA + stepB + stepC + stepD;

}