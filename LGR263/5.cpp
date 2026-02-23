#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m, k;
    bool tiKu[50][5001]={0};
    for (int i=1; i<=5000; i++){
        tiKu[0][i]=true;
    }

    scanf("%d %d %d", &n, &m, &k);
    int op, u, v;
    for (int j=0; j<k; j++){
        scanf("%d %d %d", &op, &u, &v);
        if (op == 1){
            for (int i=0; i<50; i++){
                if (tiKu[i][u]){
                    tiKu[i][u]=0;
                    tiKu[v][u]=1;
                }
            }
        }
        if (op == 2){
            int i;
            for (i=1; i<=5000; i++){
                if (tiKu[v][i]){
                    u--;
                }
                if (u==0){
                    printf("%d\n",i);
                    break;
                }
                if (i==5000) printf("-1\n");
            }
        }
    }
    return 0;
}