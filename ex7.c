#include <stdlib.h>
#include <stdio.h>

int main(){
    int N ;
    int j =0 , i , counter =1 ;
    do{
        printf("input the size of the square matrix: ");
        scanf("%d",&N);
    }while(N>25 ||N<1);
    
    int A[N][N];
    for(int i =0 ; i<N ; i++){
        j =0;
        do{
        printf("input the %dth value: ",counter);
        scanf("%d",&A[i][j]);
        if(A[i][j]<=9 &&A[i][j]>=0){
            counter++;
            j++;
        }
    }while(j<N);
    }
    for(int i =0 ; i<N; i++){
        printf("[");
        for(int j =0 ; j<N;j++){
            printf("%d ,",A[i][j]);
        }
        printf("]\n");
    }
    int sum=0 ;
    for(int i =0 ; i<N ;i++){
        sum +=A[i][i];
    }
    printf("the trace of the matrix is %d",sum);
    int index , jndex , max ;
    max = A[0][0];
    index = 0 ;
    jndex = 0 ;
    if(max==9){
        printf("the biggest element is 9 qnd it's postion is (0,0)");
    }else{
        i=0;
        while(max!=9 && i<N){
            if(max < A[i][i]){
                index=jndex=i ;
                max = A[i][i] ;
            }
            if(max<A[i][N-1-i]){
                index = i ;
                jndex = N-1-i ;
                max =A[i][N-1-i];
            }
            i++ ;
        }
        printf("\nthe max element is %d and its position is at line %d column %d",max,index+1,jndex+1);
    }
    int temp ;
    for(int i = 0 ; i<N ; i++){
        temp=A[i][i];
        A[i][i]=A[i][N-1-i];
        A[i][N-1-i]=temp ;
    }
    printf("\n");
    for(int i =0 ; i<N; i++){
        printf("[");
        for(int j =0 ; j<N;j++){
            printf("%d ,",A[i][j]);
        }
        printf("]\n");
    }
    int num , Inum ;
    num=Inum=0;
    for(int i =0 ; i<N ; i++){
        num=num*10+A[i][i];
        Inum=Inum*10+A[N-1-i][N-1-i];
    }
    printf("\n");
    printf("the number is %d and the inverse is %d",num,Inum);
    printf("\n");
    int ISlower=1 ;
    i=0;
    while(i<N-1 && ISlower){
        j=i+1;
        while(j<N && ISlower){
            if(A[i][j]!=0){
                ISlower=0 ;
            }
            j++;
        }
        i++;
    }
    if(ISlower){
        printf("the matrix is lower triangular ");
    }else{
        printf("the matrix is not lower triangular");
    }
    





    return 0;
}