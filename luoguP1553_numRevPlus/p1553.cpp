#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//TODO:
int main(){
    int type=1;
    string num;
    cin >> num;
    if(find(num.begin(), num.end(), ".")!=num.end()){
        type=2;
    }

    return 0;
}