#include <iostream>
#include <stack>

using namespace std;

int min(int* arr, int begin, int end){
    int k = begin;
    for (int i = begin; i < end; i++) {
        k = arr[i] < arr[k] ? i : k;
    }
    return k;
}

void rev(int *arr, int l, int r){
    for (int i = 0; i < (r - l + 1) / 2; i++) {
        swap(arr[l + i], arr[r - i]);
    }
}

int main() {
    int n, c;
    scanf("%d %d", &n, &c);
    int a[10002];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i=0; i<n; i++){
        rev(a, i, min(a, i, i + c > n ? n : i + c));
    }
    for (int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    return 0;
}