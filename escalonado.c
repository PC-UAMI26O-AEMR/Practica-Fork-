#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N 3


int main(){
    int t,j,i,status,t1,t2;

    // Armamos la cadena principal
    for(i=0; i<N; i++){
      if(fork()) break;
    }
    // cada proceso de la cadena principal arma su propia cadena
    for(j=0; j<i;j++){
     if(fork()) break;
    }

    if(i != 0){
        if(i != N && j == 0){
         wait(&status);
         t1 = WEXITSTATUS(status);
         wait(&status);
         t2 = WEXITSTATUS(status);
         t = t1+t2+1;
         exit(t);
        }else{
           if(i == N && j == 0){
             wait(&status);
             t =  WEXITSTATUS(status);
             t++;
             exit(t);
            }else if(i == j){ // LLegamos a una hoja
                exit(1);
                }else if(j >= 1){
                        wait(&status);
                        t = WEXITSTATUS(status);
                        t++;
                        exit(t);
                 }
         }
    }else if(N >= 1){
        wait(&status);
        t = WEXITSTATUS(status);
        t++;
        printf("Total = %d",t);
    }
}
