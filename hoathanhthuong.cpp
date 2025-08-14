#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int n; cin >> n; 
    string a; cin >> a;

    int gap = 1;
    

    for (int index = 0; index<n; index++){
        cout << a[index];
        index += gap;
        gap++;
    }
    
}