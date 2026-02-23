#include <cstdio>
#define N 512

void arr_rev(int s[])
{
    int i = 0, j = 0;
    int temp;
    while (s[j] != '\n')
        j++;
    j--;
    for (; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    return;
}

int main()
{
    int a[N]={0}, b[N]={0}, c[N]={0};
    int carry=0;
    int p, q, r;
    for (p = 0; (a[p] = getchar()) != '\n'; p++) a[p]-='0';
    for (q = 0; (b[q] = getchar()) != '\n'; q++) b[q]-='0';
    arr_rev(a); arr_rev(b);
    a[p]=0; b[q]=0;
    for (int i = 0; i<N; i++){
        c[i]=a[i]+b[i]+carry;
        carry=c[i]/10;
        c[i]%=10;
    }
    for (r=511; c[r]==0 && r>=1; r--){}
    for (; r>=0; r--) printf("%d", c[r]);
    return 0;
}