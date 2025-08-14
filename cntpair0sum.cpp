#include <iostream>
#include <map>
using namespace std;
int main() {
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }
    int n;
    cin >> n;
    long long a[n];
    
    map<long long,int> p;


    long long count=0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (p[-a[i]]>0) count+=p[-a[i]];
        p[a[i]]++;
    }
    cout << count;
}
