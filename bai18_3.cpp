#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
string name[N];

string Transform(string s){

    string ans = s;
    
    ans[0] = toupper(ans[0]);
    for (int i = 1; i<ans.size(); i++) ans[i] = tolower(ans[i]);

    return ans;
}

string upper(string s){

    string ans = s;

    for (int i = 0; i<s.size(); i++) ans[i] = toupper(ans[i]);

    return ans;
} 

int main(){
    freopen("_ab.inp", "r", stdin);
    freopen("_ab.out", "w", stdout);
    string s;
    
	getline(cin, s);
	stringstream ss(s);
	string word;
	int dem = -1;
	while(ss >> word){
		dem++;
        name[dem] = word;
        
	}

    for (int i=0; i<=dem; i++) name[i] = Transform(name[i]);

    for (int i = 0; i<dem; i++) 
    {
        if (i != dem-1) cout << name[i] << " "; 
        else cout << name[i] << ", ";
    }

    name[dem] = upper(name[dem]);

    cout<<name[dem];
}