#include <iostream>
#pragma GCC optimize(2)

using namespace std;

int main(){
    int l, m;
    bool trees[10001];
    for (int i=0; i<10001; i++){
        trees[i]=true;
    }
    int u, v;
    scanf("%d %d", &l, &m);
    for (int i=0; i<m; i++){
        scanf("%d %d", &u, &v);
        for (int j=u; j<=v; j++){
            trees[j]=false;
        }
    }
    int count=0;
    for (int i = 0; i < l+1; i++){
        if (trees[i]==true) count++;
    }
    printf("%d\n",count);
}