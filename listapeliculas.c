#include <stdio.h>
#include <stdlib.h>
#define MAX_PELI 30
#define SALIR 3

typedef struct pelicula{
    char Nombre[30];
    int Puntaje;
    struct pelicula *next;
}pelicula_t;

pelicula_t * listapeliculas=NULL;
void menu(void);
void imprimir_pelicula(pelicula_t);
void pedir_datos(pelicula_t * pelicula);
void ver_lista(void);
void cargar_pelicula(void);
void liberar_memoria(void);

int main(){
    menu();
    liberar_memoria();
    return 0;
}

void imprimir_pelicula(pelicula_t pelicula){
    printf("Nombre: %s\n",pelicula.Nombre);
    printf("Puntaje: %d\n",pelicula.Puntaje);
    printf("+++++++++++++++++++++++\n");

}
void pedir_datos(pelicula_t * pelicula){
    printf("ingrese el nombre de la pelicula:\n");
    scanf("%s",pelicula->Nombre);
    printf("ingrese el puntaje que le dio a la pelicula:\n");
    scanf("%d",&(pelicula->Puntaje));

}

void menu(void){
    int opcion;
    do{
        printf("1_Cargar una nueva pelicula\n");
        printf("2_Ver todas las peliculas cargadas\n");
        printf("3_Salir\n");
        scanf("%d",&opcion);
        if(opcion==1)cargar_pelicula();
        if(opcion==2)ver_lista();
    }while(opcion!=SALIR);
    
}

void cargar_pelicula(){
    pelicula_t *pelicula_aux;
    pelicula_aux=malloc(sizeof(pelicula_t));
    if(pelicula_aux==NULL){
        printf("Out of memory\n");
    }else{
        pedir_datos(pelicula_aux);
        pelicula_aux->next=listapeliculas;
        listapeliculas=pelicula_aux;
    }
     
        
}

void ver_lista(void){
    pelicula_t *lista=listapeliculas;
    while(lista!=NULL){
        imprimir_pelicula(*lista);
        lista=lista->next;
    }
}
void liberar_memoria(void){
    pelicula_t *aux=NULL;
    while(listapeliculas!=NULL){
        aux=listapeliculas;
        listapeliculas=listapeliculas->next;
        free(aux);

    }
    
}
