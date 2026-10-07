#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#define T 1 // tallo 
#define P 4 // petalo
#define F 3  // flores

int main(){
 pid_t pid_raiz = getpid();
 int i,j,k;
 // tallo
 for(i = 0; i<(T-1); i++){
    if(fork()) break; 
 }
 //Flores 
 if(i == (T-1)){
    for(j=1; j<F; j++){
       if(fork()) break; // detenemos el proceso del padre
    }
    if(j>0){
      // para crear la flor 
      if(!fork()){ // centro de la flor 
         for(k=0; k<P; k++){ // petalos
             if(!fork())break;
          }
       }
    }
 } 
 sleep(3000);
 return 0;
}
