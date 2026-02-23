#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, b;
    vector<int> h;
    scanf("%d %d", &n, &b);
    for (int i=0; i<n; i++){
        int hi;
        scanf("%d", &hi);
        h.push_back(hi);
    }
    sort(h.begin(), h.end(), greater<int>());
    int total = 0, count = 0;
    while (total < b){
        total+=h.at(count);
        count++;
    }
    printf("%d", count);
    return 0;
}