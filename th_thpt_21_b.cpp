#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;

bool isValid(string a, string b) {
    int j = 0;
    for (int i = 0; i < a.size(); i++) {
        if (j < b.size() && a[i] == b[j]) {
            j++;
        } else if (i > 0 && a[i] == a[i - 1]) {
            continue;
        } else {
            return false;
        }
    }
    return j == b.size();
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }
    
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    
    vector<string> words1, words2;
    string word;
    
    for (int i = 0; i<s1.size(); i++){
        if (s1[i] != ' ') word += s1[i];
        else {
            words1.push_back(word);
            word = "";
        }

        if (i == s1.size()-1) {
            words1.push_back(word);
            word = "";
        }
    }

    for (int i = 0; i<s2.size(); i++){
        if (s2[i] != ) word += s2[i];
        else {
            words2.push_back(word);
            word = "";
        }

        if (i == s2.size()-1) {
            words2.push_back(word);za
            word = "";
        }
    }

    // while (cin >> a) cout << a;
    
    int correctWords = 0;
    for (int i = 0; i < words1.size(); i++) {
        if (words1[i] == words2[i]) {
            correctWords++;
        }
    }
    
    cout << correctWords << endl;
    return 0;
}
