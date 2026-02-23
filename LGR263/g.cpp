#include <vector>
#include <iostream>
#include <ctype.h>

using namespace std;

struct unKnown
{
    char name;
    int value;
};


int main(){
    int q, n;
    vector<unKnown> unKnowns(26);
    char e[100001];
    long long lhs=0, rhs=0;
    scanf("%d", &q);
    for (int i=0; i<q; i++){
        scanf("%d", &n);
        scanf("%s", e+1);
        e[0]='+';
        for (int j=0; j<n; j++){
            scanf("%c=%d", &(unKnowns.at(j).name), &(unKnowns.at(j).value));
        }
        for (int j=0; e[j]!='='; j++){
            
        }
    }
}