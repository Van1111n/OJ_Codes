#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int min(int* arr, int begin, int end){
    int k=begin;
    for (int i = begin; i < end; i++) {
        k = arr[i] < arr[k] ? i : k;
    }
    return k;
}

int main() {
    int n, c;
    int a[10002] = {0};
    stack<int> st;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int i=0;
    while(i<n){
        int m = min(a, i, i + c - st.size() < n ? i + c - st.size() : n);
        if (st.empty() == true || a[m] < st.top()) {
            for (; i <= m; i++) {
                st.push(a[i]);
            }
        }
        printf("%d ", st.top());
        st.pop();
    }
    while(!st.empty()){
        printf("%d ", st.top());
        st.pop();
    }
    return 0;
}