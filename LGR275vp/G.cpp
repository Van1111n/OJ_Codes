#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        string s;
        cin >> s;
        for (int i=0; i<s.length()-1; i++){
            if (s.at(i)=='a'||s.at(i)=='e'||s.at(i)=='i'||s.at(i)=='o'||s.at(i)=='u'){
                s.insert(s.begin()+i+1,'|');
            }
        }
        s.insert(s.begin(),'|');
        for (int i=0; i<s.length()-1; i++){
            if(s.at(i)=='|'){
                printf("%c", toupper(s.at(i+1)));
            }
        }
        printf("\n");
    }
}