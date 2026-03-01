#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct Minister {
    int a;
    int b;
    bool operator<(const Minister& m) {
        if (max(m.b, b * a) < max(b, m.b * m.a))
            return true;
        else
            return false;
    }
};
struct EmpErroR {
    int a;
    int b;
};

void big_num_prt(int a[4005]) {
    int k;
    for (k = 4004; k >= 0; k--) {
        if (a[k] != 0)
            break;
    }
    for (; k >= 0; k--) {
        printf("%d", a[k]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    vector<Minister> ministers;
    EmpErroR emperror;
    scanf("%d %d", &emperror.a, &emperror.b);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        ministers.push_back({a, b});
    }
    sort(ministers.begin(), ministers.end());

    int product[4005]={0}, gold[4005]={0}, maxGold[4005]={0};
    product[0] = emperror.a;
    for (int i = 0; i < 4004; i++) {
        if (product[i] >= 10) {
            product[i + 1] += product[i] / 10;
            product[i] %= 10;
        }
    }
    for (int i = 0; i < n; i++) {
        int k;
        for (k = 4004; k >= 0; k--) {
            if (product[k] != 0)
                break;
        }
        int d = 0, r = 0;
        for (; k >= 0; k--) {
            d = 10 * r + product[k];
            gold[k] = d / ministers[i].b;
            r = d % ministers[i].b;
        }
        for (int j=4004; j>=0; j--){
            if (gold[j]>maxGold[j]){
                for (int k=0; k<4005; k++) maxGold[k]=gold[k];
                break;
            }
        }
        //big_num_prt(product); big_num_prt(gold);
        for (int j = 0; j < 4005; j++) {
            product[j] *= ministers[i].a;
        }
        for (int j = 0; j < 4005; j++) {
            if (product[j] >= 10) {
                product[j + 1] += product[j] / 10;
                product[j] %= 10;
            }
        }
    }
    big_num_prt(maxGold);
}