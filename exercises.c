#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) { 
  int temp = 0;
  for(int i = 0 ; i < size ; i++){
    if(temp < arr[i]) temp = arr[i];
  }
  return temp; 
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void copyArr(int CpArr[], int arr[], int size){
  for(int i = 0 ; i < size ; i++){
    CpArr[i] = arr[i];
  }
}

void reverseArray(int arr[], int size) {
  int tempArr[size];
  copyArr(tempArr, arr, size);
  for(int i = 0 ; i < size ; i++){
    arr[i] = tempArr[size - 1 - i];
  }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) {
  int *newArr = (int *)malloc(sizeof(int) * size);
  int cont = 0;
  for (int i = 0; i < size; i++){
    if (arr[i] % 2 == 0){
      newArr[cont] = arr[i];
      cont++;
    }
    *newSize = cont;
  }
  return newArr;
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void ordenarArr(int newArr[], int size){
  int temp = 0;
  for(int i = 0 ; i < size ; i++){
    for(int j = 0 ; j < size ; j++){
      if(newArr[i] < newArr[j]){
        temp = newArr[i];
        newArr[i] = newArr[j];
        newArr[j] = temp;
      }
    }
  }
}

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,
                       int result[]) {
  int cont = 0;
  for (int i = 0; i < size1; i++){
    result[cont] = arr1[i];
    cont++;
  }
  for (int i = 0; i < size2; i++){
    result[cont] = arr2[i];
    cont++;
  }
  ordenarArr(result, size1 + size2);
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) {
  int contAscendente = 1, contDescendiente = 1;

  for (int i = 1; i < size; i++) {
    if (arr[i] < arr[i - 1]) contAscendente = 0;
    if (arr[i] > arr[i - 1]) contDescendiente = 0;
  }

  if (contAscendente) return 1;
  else if (contDescendiente) return -1;
  else return 0;
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,
                      int anioNacimiento, int anioPublicacion) {
  strcpy(libro->titulo, titulo);
  strcpy(libro->autor.nombre, nombreAutor);
  libro->autor.anioNacimiento = anioNacimiento;
  libro->anioPublicacion = anioPublicacion;
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) {
  Nodo *cabeza = NULL, *temp = NULL, *actual = NULL;
  for (int i = 0; i < size; i++){
    temp = (Nodo *)malloc(sizeof(Nodo));
    temp->numero = arr[i];
    temp->siguiente = NULL;

    if (cabeza == NULL) cabeza = temp;
    else actual->siguiente = temp;
    actual = temp;
  }
  return cabeza;
}
