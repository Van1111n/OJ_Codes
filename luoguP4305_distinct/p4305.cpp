#include <iostream>
#include <algorithm>

struct Num{
    int pos;
    int val;
};

void prt_num(Num* nums, int length){
    for (int i=0; i<length; i++){
        printf("%d %d\n", nums[i].val, nums[i].pos);
    }
}

int val_comp(const void* p1, const void* p2){
    Num *a=(Num*)p1, *b=(Num*)p2;
    return a->val == b->val ? a->pos - b->pos : a->val < b->val ? -1 : 1;
}

int pos_comp(const void* a, const void* b){
    return ((Num*)a)->pos - ((Num*)b)->pos;
}

int main(){
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++){
        int n;
        Num *nums;
        scanf("%d", &n);
        nums = (Num*)malloc(n * sizeof(Num));
        for (int i=0; i<n; i++){
            nums[i].pos=i;
            scanf("%d", &nums[i].val);
        }
        qsort(nums, n, sizeof(Num), val_comp);
        //prt_num(nums, n);  //Debug printf
        int prev=nums[0].val;
        for (int i=1; i<n; i++){
            if (nums[i].val==prev){
                nums[i].pos=-1;
                continue;
            } else {
                prev=nums[i].val;
            }
        }
        qsort(nums, n, sizeof(Num), pos_comp);
        for (int i=0; i<n; i++){
            if (nums[i].pos!=-1) printf("%d ", nums[i].val);
        }
        printf("\n");
    }
}