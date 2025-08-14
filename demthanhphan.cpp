#include <iostream>
#include <string>
#include <ctype.h>
#include <sstream>
#include <vector>

using namespace std;

int main(){

    if (fopen("_ab.inp", "r")) {
            freopen("_ab.inp", "r", stdin);
            freopen("_ab.out", "w", stdout);
        }
    
	string name; 
    getline(cin, name);
	//chuan hoa ten
    for(int i = 0; i < name.size(); i++){
		name[i] = tolower(name[i]);
	}

    //Tach tu
	stringstream ss(name);
	vector<string> v;
	string word;

	while(ss >> word){
		v.push_back(word);
	}

    for (int i = 0; i<v.size(); i++) cout << v[i] << " ";
    cout <<  '\n';

	string email = v[v.size() - 1]; // ten

	for(int i = 0; i < v.size() - 1; i++){
		email += v[i][0]; // ki tu dau tien cua ho va dem
	}

	email += "@gmail.com";
	cout << email << endl;
}