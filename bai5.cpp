#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6+5;
int factors[N];
int powerOfFactors[N];

void findSum(int n)
{
    int temp = n;
    int indexFactors = 0;
    int indexpowerOfFactors = 0;

    for(int i = 2; i <= ceil(sqrt(n)); i++)
    {
        int factor = -1;
        int powerOfFactor = 0;
        while((temp != 1) && (temp%i == 0))
        {
            powerOfFactor++;
            factor = i;
            temp = temp/i;
        }
        if(factor != -1)
        {
            indexFactors++;
            factors[indexFactors] = factor;
            indexpowerOfFactors++;
            powerOfFactors[indexpowerOfFactors] = powerOfFactor;
        }
    }
    //Nếu temp != 1, tức là ta chưa phân tích hết nó thành các thừa số nguyên tố
    //temp chính là số nguyên tố còn lại mà vòng for không chạm đến
    //Vì vậy, ta phải thêm vào mảng thừa số (factors) temp và số mũ của nó (1)
    if(temp != 1)
    {
        indexFactors++;
        factors[indexFactors] = temp;
        indexpowerOfFactors++;
        powerOfFactors[indexpowerOfFactors] = 1;
    }

    long long ans = 1;
    long long ans1 = 1;

    for(int i = 1; i <= indexFactors; i++)
    {
        long long temp = (pow(factors[i], powerOfFactors[i] + 1) - 1);
        temp /= (factors[i] - 1);
        ans *= temp;
        ans1 *= (powerOfFactors[1] + 1);
    }
    cout << ans1 << " " << ans << '\n';
}

int main()
{
    if (fopen("_ab.inp", "r")) {
            freopen("_ab.inp", "r", stdin);
            freopen("_ab.out", "w", stdout);
        }
    
    int t; cin >> t;
    int A[t+1];
    for(int i = 1; i <= t; i++)
    {
        cin >> A[i];
    }
    for(int i = 1; i <= t; i++)
    {
        findSum(A[i]);
    }
}