#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    string name1, name2, name3, name4;
    getline(cin, name1);
    getline(cin, name2);
    getline(cin, name3);
    getline(cin, name4);
    
    
    //cout << name1 << '\n' << name2 << '\n' << name3 << '\n' << name4;

    //Mot xau co do dai n ky tu se bat bang chi so 0 va ket thuc bang n-1.
    
    string s = "HELLO";
    cout << s[-1]  << " " << s[5];

    //Duyet xau
    for (int i = 0; i<s.size(); i++) cout << s[i] << " ";
    
    //For-each
    for (char c:s) cout << c << " ";

    //Do dai cua sau
    cout << s.length() << " " << s.size();
    

    //Concatenataion, ghep xau, noi xau, ...
    string s1 = "ab";
    string s2 = "cd";
    
    //s1 = s1 + s2;
    s1 = s2 + s1;

    s = "12345";

    string ans = "789";

    ans.append("12345");

    string firstName = "John ";
    string lastName = "Cena";

    string fullName = firstName.append(lastName);

    cout << fullName << '\n';


    //append(): Thêm vào, đính vào

    string num1 = "10";
    //int num2 = 20;

    //string num3 = num1 + num2;

    //cout << num3;

    //at(): lấy vị trí của một ký tự tại vị trí i bất kì

    s = "12345";

    cout << s.at(s.size() - 1);

    //

    /*
    
    */

   //Escape Sequence 
   cout << 1 << '\r' << 2 << '\r' << 3 << endl; //a: alert 

   string a = "abcf";
   string b = "!ef";

   //cout << '!' + 0 << " " << 'a' + 0;

   //if (a<b) cout << "Nho hon";
   //if (a>b) cout << "Lon hon";
   //if (a == b) cout << "Bang nhau";

   //Quy doi ASCII

   //Character -> ASCII: c + 0;

   s = "112hjhoo0921opkdapd";
   string c = "";
   string numberN = "";

   for (int i = 0; i<s.size(); i++){

        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) c += s[i];
        if (s[i] >= '0' && s[i] <= '9') numberN += s[i];
   }

   cout << c << " " << numberN << " ";
   
    string xau1 = "1234";
    string xau2 = "124";

    //cout << xau1.compare(xau2);

    //substr sub 1, sub 2

    s = "123456";
    s1 = s.substr(2, 10);
    cout << s1;

    //

    string number = "123456789";
    long long ansNumber;

    
    //48, 57
    /*
    while (number != 0){
        int temp = number%10;
        if (temp == 1) ansNumber = '1' + ansNumber;   
        if (temp == 2) ansNumber += '2';
        if (temp == 3) ansNumber += '3';
        if (temp == 4) ansNumber += '4';
        if (temp == 5) ansNumber += '5';
        if (temp == 6) ansNumber += '6';
        if (temp == 7) ansNumber += '7';
        if (temp == 8) ansNumber += '8';
        if (temp == 9) ansNumber += '9';
        if (temp == 0) ansNumber += '0';
        number = number/10;
    }


    cout << ansNumber;

    */

   
   

}