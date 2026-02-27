#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int m, s, c;
    bool stat[205]={0};
    scanf("%d %d %d", &m, &s, &c);
    int temp;
    for (int i = 0; i < c; i++) {
        scanf("%d", &temp);
        stat[temp] = true;
    }

    int min=1, max=s;
    while(stat[min]==false){
        min++;
    }
    while(stat[max]==false){
        max--;
    }

    vector<int> emptyLengths;
    int p=min, q=min;
    while (q <= max) {
        if (stat[p] == true) {
            ++p;
            ++q;
            continue;
        } else {
            while (stat[q] == false && q <= max) {
                ++q;
            }
            emptyLengths.push_back(q - p);
            p = q;
        }
    }

    sort(emptyLengths.begin(), emptyLengths.end());
    int totLength=max-min+1;
    for (int i=0; i<m-1; i++){
        if (emptyLengths.empty()) break;
        totLength-=emptyLengths.back();
        emptyLengths.pop_back();
    }
    printf("%d\n", totLength);

    return 0;
}