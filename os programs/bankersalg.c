#include<stdio.h>
#include <stdlib.h>

void takeMatrixInput(int rows,int cols,int matrix[rows][cols]){
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            printf("matrix[%d][%d]: ",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
    }
}

void printMatrix(int rows,int cols,int matrix[rows][cols]){
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n,m;
    printf("Enter no.of rows and cols: ");
    scanf("%d %d",&n,&m);
   
    int allocation[n][m], max[n][m] ,need[n][m], available[m],allocated[n];

    int visited[n][m];
    
    printf("Enter values for allocation matrix:\n");
    takeMatrixInput(n,m,allocation);

    printf("Enter values for max:\n");
    takeMatrixInput(n,m,max);

    printf("allocation matrix is:\n");
    printMatrix(n,m,allocation);

    printf("max matrix is:\n");
    printMatrix(n,m,max);

    printf("need matrix is:\n");
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            printf("%d ",need[i][j] = max[i][j] - allocation[i][j]);
            visited[i][j] = 0;
        }
        printf("\n");
    }

    printf("available matrix: \n");
    for(int i = 0;i < m;i++){
        printf("matrix[%d]: ",i+1);
        scanf("%d",&available[i]);
    }
    printf("\n");

    for(int i = 0;i < m;i++){
        printf("%d ",available[i]);

    }


    int count = 0;
    int flag = 0;
    int counts = 0;
    int iteration = 0;
    
while(iteration < n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(need[i][j] <= available[j] && visited[i][j] == 0){
                count++;
            }
        }

        if(count == m){
            allocated[flag++] = i+1;
            for(int k = 0;k < m;k++){
                available[k] = available[k] + allocation[i][k];
                visited[i][k] = 1;
            }
        }
        count = 0;
    }
    
    
    for(int x = 0;x<n;x++){
        for(int y = 0;y<m;y++){
            if(visited[x][y] == 1){
                counts++;
            }
        }
    }

    int value = n * m;
    if(counts == value){
        printf("safe state\n");
        printf("The safe sequence is: ");
        for(int z = 0;z<flag;z++){
            printf("%d ",allocated[z]);
        }
        exit(0);
    }else{
        counts = 0;
        iteration++;
        if (iteration == n) {
            printf("Unsafe state, the unsatisfied processes are: \n");
            int unsatisfied_rows[n];
            int unsatisfied_count = 0;
            for (int i = 0; i < n; i++) {
                int flag = 1;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        flag = 0;
                        break;
                    }
                }
                if (!flag) {
                    unsatisfied_rows[unsatisfied_count++] = i + 1;
                }
            }
            
            for(int i = 0;i<unsatisfied_count;i++){
                printf("%d ",unsatisfied_rows[i]);
            }
            exit(0);
    }
}
}
    return 0;
}
