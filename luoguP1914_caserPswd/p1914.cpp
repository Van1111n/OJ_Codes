#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    for (int i=0; i<s.length(); i++){
        s[i]+=n;
        if (s[i]>'z'||s[i]<'a') s[i]-=26;
    }
    cout << s;
}