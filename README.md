# Gestiòn de Procesos en C 
se realizaron ejemplos practicos para la creacion, sincronizaciòn y comunicacion de procesos 
en C utilizando llamadas al sistema con `fork()`,`wait()` y `exit()`
Para la visualizacion de la jerarquia de procesos en tiempo de ejecucion usamos el comando 
```
pstree -p $(pgrep -o nombre_archivo)

```
## 1. Arbol de Procesos Escalonado 
Se creo un arbol triangular/escalonado de procesos donde cada 
nivel i genera su proia subacadena 
* Formula que sigue este proceso:  $\frac{(N+1)(N+2)}{2}$

 ## 2. Arbol en Forma de Flor
 se Creo una estructura donde un tallo principal genera nodos que asu vez crean
 multiples pètalos 
 
