#include <bits/stdc++.h>

using namespace std;

struct s{
    int clsNo;
    int NumOfPeople;

    bool operator < (const s& other){
        return clsNo < other.clsNo;
    }
};

int main(){
    vector<s> classes(71);
    for (int i=0; i<71; i++){
        cin >> classes.at(i).clsNo >> classes.at(i).NumOfPeople;
    }
    sort(classes.begin(), classes.end());

    for (auto it:classes){
        printf("%d, ", it.NumOfPeople);
    }

    return 0;
}