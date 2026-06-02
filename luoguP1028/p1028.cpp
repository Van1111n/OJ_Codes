#include <iostream>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int f[1000];
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j <= i / 2; j++){
            f[i]+=f[j];
        }
    }
    printf("%d", f[n]);
}