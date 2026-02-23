#include <iostream>

using namespace std;

int arr[20]={0};
void dfs(int l, int r, int k, int layer){
    if (k==0){
        for (int i=0; i<layer; i++){
            printf("%3d", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = l; i <= r - k + 1; i++) {
        arr[layer]=i;
        dfs(i + 1, r, k - 1, layer+1);
    }
}

int main(){
    int n, r;
    scanf("%d %d", &n, &r);
    dfs(1,n,r,0);
    return 0;
}