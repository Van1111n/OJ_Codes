#include <iostream>

using namespace std;

//2ks+k=m, 
int main(){
    int k, m, s;
    scanf("%d %d", &k, &m);
    s = (m - k) / 2 / k;
    printf("%d\n", s);
}