#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
string s;
set<string> answer;

string clean(string temp) {

    while (temp.size() > 1 && temp[0] == '0') temp.erase(0, 1);

    //cout << newTemp << '\n';
    return temp;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> s;

    string temp = "";

    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            temp += s[i];
        }

        else {
            if (temp != "") {
                temp = clean(temp);
                answer.insert(temp);
                temp = "";
            }
        }
    }

    if (temp != "") {
        temp = clean(temp);
        answer.insert(temp);
        temp = "";
    }

    cout << answer.size();
}