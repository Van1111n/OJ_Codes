#include <string>
#include <iostream>

using namespace std;

int main(){
    string s;
    int count = 0;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i)!=' ') count++;
    }
    cout << count;
}