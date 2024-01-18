#include <stdio.h>
#include <stdlib.h>
void printArr(int T[],int N) {
     printf("\n");
    printf("[");
    for(int i=0 ; i<N;i++){
        printf("%d , ",T[i]) ;
    }
    printf("]");
    
}

int main (){
int N ;
printf("input the number N the size of array:");
scanf("%d",&N);
int T[N] ;
int mod ;
int counter=0;
for(int i=0 ; i<N; i++){
    T[i]=i+1 ;
}
printArr(T,N);

for(int i=1 ; i<N/2 ; i++){
    if(T[i]!=0){
        for(int j = i+1 ; j<N ; j++){
            mod=T[j]%T[i] ;
            if(mod==0) {T[j]=0;}
        }
    }
}
printArr(T,N);
 int i = 2 ;
while(i<N-counter){
    if(T[i]==0){
        counter ++ ;
        for (int j = i ; j<N-i+2 ; j++){
            T[j]=T[j+1];
        }
    }else {i++ ;}


}
 printArr(T,N);
N=N-counter ;
for(int i = 0 ; i<N-1 ; i++){

    T[i]=T[i+1];
}
N=N-1 ;
printf("%d",N);
printArr(T,N);



   return 0;
}