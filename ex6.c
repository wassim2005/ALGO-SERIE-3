#include <stdlib.h>
#include <stdio.h>


int main (){
    int N , M , sum , Jmin , Jmax , max ;
    printf("input the number of lines N :");
    scanf("%d",&N);
    printf("input the number of columns  M :");
    scanf("%d",&M);
    int A[N][M] ;
    int counter = 1 ;
    for(int i = 0 ; i<N ; i++){
        for(int j = 0 ; j<M ; j++){
            printf("input your %dth value: ",counter);
            scanf("%d",&A[i][j]);
            counter++;
        }
    }
    for(int i =0 ; i<M; i++){
        printf("[");
        for(int j =0 ; j<N;j++){
            printf("%d ,",A[i][j]);
        }
        printf("]\n");
    }
    int Sum[M];
    for(int i = 0 ; i<M ; i++){
        sum = 0 ;
        for(int j =0 ; j<N ; j++){
            sum+=A[j][i];
        }
        Sum[i]=sum ;
    }
    printf("[");
    for(int i=0;i<M;i++){
        printf("%d ,",Sum[i]);
    }
    printf("]\n");
    max=Sum[0];
    Jmax=0;
    sum = Sum[0];
    Jmin=0;
    for (int i = 1; i < N; i++)
    {
        if(max<Sum[i]){
            max = Sum[i];
            Jmax=i;
        }else if (sum>=Sum[i]){
            sum=Sum[i];
            Jmin=i;
        }
        
    }
    int temp;
    if(Jmin>Jmax){
        for(int i = 0 ; i<M;i++){
            temp=A[i][Jmin];
            A[i][Jmin]= A[i][Jmax];
            A[i][Jmax] = temp ;

        }
    }
    for(int i =0 ; i<M; i++){
        printf("[");
        for(int j =0 ; j<N;j++){
            printf("%d ,",A[i][j]);
        }
        printf("]\n");
    }
    






    return 0;
}