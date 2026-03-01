#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define LLU unsigned long long

using namespace std;

struct Minister{
    int a;
    int b;
    bool operator < (const Minister& m){
        if (max(1.0F / b, (float)a / m.b) < max(1.0F / m.b, (float)m.a / b)) return true;
        else return false;
    }
};
struct EmpErroR{
    int a;
    int b;
};

int main(){
    int n;
    scanf("%d", &n);
    vector<Minister> ministers;
    EmpErroR emperror;
    scanf("%d %d", &emperror.a, &emperror.b);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        ministers.push_back({a,b});
    }
    sort(ministers.begin(), ministers.end());

    LLU product=emperror.a, gold, maxGold=0;
    for (int i=0; i<n; i++){
        gold = product / ministers[i].b;
        maxGold = gold > maxGold ? gold : maxGold;
        product *= ministers[i].a;
    }
    printf("%d\n", maxGold);
}