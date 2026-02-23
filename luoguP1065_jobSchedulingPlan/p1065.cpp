#include <stdio.h>
#include <stdlib.h>
#define N 400

int main()
{
    int m, n;
    int machines[20][400] = {0};
    int plan[400] = {0};
    int process[20][20] = {0}, time[20][20] = {0};
    int count[20]={0};
    int lastAppearTime[20];
    for(int i=0; i<20; i++){
        lastAppearTime[i]=-1;
    }

    scanf("%d %d", &m, &n);
    for (int i = 0; i < m * n; i++){
        scanf("%d", &plan[i]);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &process[i][j]);
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &time[i][j]);
        }
    }

    for (int i=0; i<m*n; i++){
        int j;
        for (j=lastAppearTime[plan[i]-1]+1; ; j++) {
            bool found=true;
            for (int k=0; k<time[plan[i]-1][count[plan[i]-1]]; k++){
                if (machines[process[plan[i]-1][count[plan[i]-1]]-1][j+k]!=0) found=false;
            }
            if (found) break;
        }
        for (int k=0; k<time[plan[i]-1][count[plan[i]-1]]; k++){
            machines[process[plan[i]-1][count[plan[i]-1]]-1][j+k]=plan[i];
        }
        lastAppearTime[plan[i]-1]=j+time[plan[i]-1][count[plan[i]-1]]-1;
        count[plan[i]-1]++;
    }

    int totalTime=0;
    int times[20];
    for (int i=0; i<20; i++){
        for (int j=399; j>=0; j--){
            if (machines[i][j]!=0){
                times[i]=j+1;
                break;
            }
        }
        if (times[i]>totalTime) totalTime=times[i];
    }
    printf("%d",totalTime);

    return 0;
}