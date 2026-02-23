#include <stdio.h>
using namespace std;

int main() {
    int n;
    int count = 0;
    int found[1001] = {0};
    scanf("%d", &n);
    int cur;
    for (int i = 0; i < n; i++) {
        scanf("%d", &cur);
        if (found[cur] == 0) {
            found[cur] = 1;
            count++;
        }
    }
    printf("%d\n", count);
    for (int i = 1; i <= 1000; i++) {
        if (found[i]) {
            printf("%d ",i);
        }
    }
    return 0;
}