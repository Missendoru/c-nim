#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
    #define CLEAR system("cls")
#else
    #define CLEAR system("clear")
#endif

void display(int palos){
    printf("--- Tablero ---\n");
    for(int i = 0;i<3;i++){
        for(int k = 0;k<palos;k++){
                printf("| ");
            }
            printf("\n");
        }
    printf("\n Quedan %d palos\n", palos);
}

int check(int *palos, int status, int take){
        *palos -= take;
        if(*palos == 1){ return (status == 1) ? 1 : 2; }
        if(*palos <= 0){ return (status == 1) ? 2 : 1; }
    return 0;
}

int main(void){
    
    int palos = 15;
    int take = 0;
    int status = 1;
    int gan = 0;
    srand(time(NULL));
    printf("Juego del Nim\nEl que tome el último palo pierde el juego\n");
    while(gan == 0){
        display(palos);
        do{
            printf("Escribe el número de palos que desea tomar. Solo debe ser de entre uno a tres palos: ");
            scanf("%d", &take);
        }while(take > 3 || take < 1 || take > palos);
        gan = check(&palos, status, take);
        printf("Tomaste %d palos de la pila\n", take);
        if(gan != 0){break;}
        status = 2;
        int numpalos = rand() % ((palos < 3) ? palos : 3) + 1;
        gan = check(&palos, status, numpalos);
        printf("La computadora tomó %d palos de la pila\n", numpalos);
        status = 1;
        take = 0;
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("\nPresiona cualquier tecla para continuar");
        getchar();
        CLEAR;
    }
    if(gan == 1){printf("\n\nGanaste el juego. La computadora tomó el último palo.");}
    else{printf("\n\nPerdiste. Tomaste el último palo.");}
    return 0;    
}
