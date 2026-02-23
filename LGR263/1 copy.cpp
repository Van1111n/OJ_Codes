#include <iostream>

int main(){
    int matrix[4][4];
    bool find[5];
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (matrix[i][j]==0){
                for (int i=1; i<=4; i++) find[i]=false;
                for (int k=0; k<4; k++){
                    find[matrix[i][k]]=true;
                }
                for (int k=0; k<4; k++){
                    find[matrix[k][j]]=true;
                }
                int count=0, unFound=0;
                for (int k=1; k<=4; k++){
                    if (find[k]==true) count++;
                    else unFound=k;
                }
                if (count == 3){
                    matrix[i][j] = unFound;
                }
            }
        }
    }
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (matrix[i][j]==0){
                for (int i=1; i<=4; i++) find[i]=false;
                for (int k=0; k<4; k++){
                    find[matrix[i][k]]=true;
                }
                for (int k=0; k<4; k++){
                    find[matrix[k][j]]=true;
                }
                int count=0, unFound=0;
                for (int k=1; k<=4; k++){
                    if (find[k]==true) count++;
                    else unFound=k;
                }
                if (count == 3){
                    matrix[i][j] = unFound;
                }
            }
        }
    }
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (matrix[i][j]==0){
                for (int i=1; i<=4; i++) find[i]=false;
                for (int k=0; k<4; k++){
                    find[matrix[i][k]]=true;
                }
                for (int k=0; k<4; k++){
                    find[matrix[k][j]]=true;
                }
                int count=0, unFound=0;
                for (int k=1; k<=4; k++){
                    if (find[k]==true) count++;
                    else unFound=k;
                }
                if (count == 3){
                    matrix[i][j] = unFound;
                }
            }
        }
    }for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (matrix[i][j]==0){
                for (int i=1; i<=4; i++) find[i]=false;
                for (int k=0; k<4; k++){
                    find[matrix[i][k]]=true;
                }
                for (int k=0; k<4; k++){
                    find[matrix[k][j]]=true;
                }
                int count=0, unFound=0;
                for (int k=1; k<=4; k++){
                    if (find[k]==true) count++;
                    else unFound=k;
                }
                if (count == 3){
                    matrix[i][j] = unFound;
                }
            }
        }
    }
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (matrix[i][j]==0){
                for (int i=1; i<=4; i++) find[i]=false;
                for (int k=0; k<4; k++){
                    find[matrix[i][k]]=true;
                }
                for (int k=0; k<4; k++){
                    find[matrix[k][j]]=true;
                }
                int count=0, unFound=0;
                for (int k=1; k<=4; k++){
                    if (find[k]==true) count++;
                    else unFound=k;
                }
                if (count == 3){
                    matrix[i][j] = unFound;
                }
            }
        }
    }
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (matrix[i][j]==0){
                for (int i=1; i<=4; i++) find[i]=false;
                for (int k=0; k<4; k++){
                    find[matrix[i][k]]=true;
                }
                for (int k=0; k<4; k++){
                    find[matrix[k][j]]=true;
                }
                int count=0, unFound=0;
                for (int k=1; k<=4; k++){
                    if (find[k]==true) count++;
                    else unFound=k;
                }
                if (count == 3){
                    matrix[i][j] = unFound;
                }
            }
        }
    }
    

    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            printf("%d", matrix[i][j]);
            if (j!=3) printf(" ");
        }
        printf("\n");
    }
    return 0;
}