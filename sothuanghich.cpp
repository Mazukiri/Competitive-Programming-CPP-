#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int n;

bool checkPalindrome(int x){

    int temp = x; //temp = 12345

    int power = to_string(x).size() - 1; //power = 4

    int reverseX = 0; 

    while (temp > 0){

        cout << reverseX << " " << temp << " " << power << '\n';
        int digit = temp%10;
        reverseX += (digit * pow(10, power));

        power--;
        temp /= 10;
    }

    cout << reverseX << " " << temp << " " << power << '\n';

    return (reverseX == x);

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cout << checkPalindrome(12321);
}