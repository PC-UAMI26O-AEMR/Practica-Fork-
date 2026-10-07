# Gestiòn de procesos 
los procesos en un sistema __sistemas basados en Unix__ tienen una estructura __jeràrquica__: un proceso puede crear un nuevo proceso, y este asu vez puede crear otro procesos y asì  sucesivamente. Es importante mencionar que cuando un proceso crea un nuevo proceso, al proceso creado se le llama __proceso hijo__ y al proceso del que se genero se le conoce como __proceso padre__ 

```
Bibliotecas importantes 
#include <unistd.h> // fork(), getpid(), getppid()
#include <sys/wait.h> // wait() 
#include <stdlib.h> // exit()
```

## wait() y exit()
* `wait()` :  Le indica al proceso padre que espere a que uno de sus procesos hijos termine, la funcion puede recibe como parametro

      *   `wait(NULL)` lo cual indica que no quieres la info sobre como termino
  
      * `wait(int *)` para obtener info  sobre còmo termino el hijo, si termino de forma normal, fue detenido por una señal o ocurrio `x` cosa .
  
      * `WIFEXITED(status)` : recibe un valor distinto de cero si el hijo terminò normalmente (es decir, con return o exit(), no por una señal)
      * `WEXITSTATUS(staus)`: da el valor con el que termino el hijo. Solo tiene sentido consultar si WIFEXITED(stauts) fue distinto de cero
  
* `exit()` : Sirve para terminar el proceso de manera voluntaria, existen 256 valores que pueden terminar un proceso
   
## Comando para la visualizaciòn de la jerarquia de procesos 
para poder observar la gerarquia de procesos exiten dos formas posibles para poder visualizarlas, ambas opciones muestran la jaraquia en la terminal, si quieres guardar la infor en un archivo aparte puedes redireccionar la salida a un archivo te texto con `> nombre_archivo.txt` 
* `pstree -p $(pgrep -o nombre_archivo) > visualizacion` 
* `pstree -c -p "Pid_proceso_inicial" > visualizacion`
## Ejercicios
## Ejercicio 1: Árbol de Procesos Escalonado

A diferencia de una cadena lineal de procesos simples, en este ejercicio cada proceso de la cadena principal se ramifica hacia una subcadena propia de longitud progresiva. 

Esto genera una estructura en forma de **árbol escalonado o triangular**, donde cada fila $i$ (con $i$ en el rango de $0$ a $N$) contiene $i + 1$ procesos.

El total de procesos creados en el árbol se calcula mediante la suma aritmética:

$$T = 1 + 2 + 3 + \dots + (N + 1) = \frac{(N + 1)(N + 2)}{2}$$

> **Nota:** Al finalizar la ejecución, el **proceso raíz** debe ser el encargado de recopilar la información e imprimir el número total de procesos creados.

## Ejercicio 2: Árbol de Procesos en Forma de Flor

En este ejercicio se implementa una jerarquía de procesos que modela la estructura geométrica de una flor compuesta por un **tallo**, **flores (o ramificaciones)** y **pétalos**.
###  Dinámica y Estructura del Árbol
- **Tallo:** Una cadena lineal de $T$ procesos conectados secuencialmente mediante `fork()`.
- **Flores y Pétalos:** Cada proceso perteneciente al tallo actúa como el centro de una flor y crea $P$ procesos hijos independientes que representan los pétalos.
- **Sincronización (`wait()` / `exit()`):** Cada centro de flor recolecta el estado y conteo de sus pétalos, acumulándolo a lo largo de la cadena del tallo hasta que el proceso raíz imprime la cifra final. 
 
