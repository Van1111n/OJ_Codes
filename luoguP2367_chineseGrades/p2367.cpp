#include <iostream>

int main(){
    int studentNum, operateNum;
    scanf("%d %d", &studentNum, &operateNum);
    int* students = new int[studentNum];
    int *difference = new int [studentNum];
    //int students[50], difference[50];
    for (int i=0; i<studentNum; i++){
        scanf("%d", &students[i]);
        difference[i] = students[i] - (i == 0 ? 0 : students[i - 1]);
    }
    
    for (int i=0; i<operateNum; i++){
        int l, r, add;
        scanf("%d %d %d", &l, &r, &add);
        --l, --r;
        difference[l] += add;
        if (r + 1 < studentNum)
            difference[r + 1] -= add;
    }
    int low=100;
    for (int i=0; i<studentNum; i++){
        students[i] = difference[i] + (i - 1 >= 0 ? students[i - 1] : 0);
        low = students[i] < low ? students[i] : low;
    }
    printf("%d\n", low);
    return 0;
}