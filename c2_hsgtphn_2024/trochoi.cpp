#include <bits/stdc++.h>
using namespace std;
 pair<long long,long long> a[100005];
long long  b[100005];
long long n,m;

void sub1() {
    int ln=0, vt;
    vector<int>  s(n),e(n);
    for(int i=0; i<n; i++)
    {
        cin>>s[i]>>e[i];
        if(ln<e[i])
        {
            ln=e[i];
            vt=i;
        }
    }
    if(m==2)
    {
        int k[n];
        for(int i=0; i<n;  i++)
        {
            long long j=s[i];
            s[i]=s[i]+e[i];
            
            e[i]=j+e[i]*2;

        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());

        if(s[n-1]+s[n-2]>e[n-1]) cout<<s[n-1]+s[n-2];
        else cout<< e[n-1];
    }
}


void sub2(){
    for(int i=0; i<n; i++)
    {
        cin>>a[i].second>>a[i].first;
        b[i]=a[i].first+a[i].second;
    }
    sort(a,a+n,greater<pair<long long,long long>> ());
    sort(b,b+n,greater<long long>());
  
    long long mx= a[0].first+a[0].second;
    long long ln=a[0].first,dem=0;
    long long tong =0;
    bool check =1;
    for (int i=0; i<n; i++)
    {
        if(b[i]>ln && dem<=m)
        {
            tong +=b[i];
            dem++;
            if(b[i]==mx) check=0;
        }
        else
            break;
    }
    if(dem== m)
    {
        cout<< tong;
        return;
    }
    else
    {
        m-=dem;
        if(check) tong +=m*ln+a[0].second;
        else tong+=m*ln;
    }
    cout<< tong;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("TROCHOI.INP","r",stdin);
    // freopen("TROCHOI.OUT","w",stdout);
    
    cin>> n>> m;

    if (m == 2) sub1();
    else sub2();
}
