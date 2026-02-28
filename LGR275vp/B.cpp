#include <iostream>

using namespace std;

int main() {
    int a, b, x, y, m;
    scanf("%d %d %d %d %d", &a, &b, &x, &y, &m);
    if (x>y){
        swap(a,b);
        swap(x,y);
    }
    int count=0;
    while (m >= x && a > 0) {
        --a;
        m -= x;
        ++count;
    }
    while (m >= y && b > 0) {
        --b;
        m -= y;
        ++count;
    }
    printf("%d", count);
}