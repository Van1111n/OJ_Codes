#include <iostream>
#include <algorithm>
#define N 100000

using namespace std;

void quick_sort(int arr[], int len) {
    if (len <= 1)
        return;
    int m = arr[0];
    int i = 1, j = len - 1;
    while (i < j) {
        if (arr[i] > m) {
            swap(arr[i], arr[j--]);
            continue;
        } else {
            i++;
            continue;
        }
    }
    if (arr[i] > m){
        i--;
    } else {
        j++;
    }
    swap(arr[0], arr[i]);
    quick_sort(arr, i);
    quick_sort(arr+j, len-j);
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    quick_sort(a, n);
    for (int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}