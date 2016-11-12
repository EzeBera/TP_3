#include "stddef.h"
#include "stdio.h"
#include "stdlib.h"


typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
}EMovie;
EMovie *movie_newFull();
EMovie* movie_search(EMovie*[],char[20]);
   int contadorPeliculas=0;
    EMovie *peliculas[5];

int main()
{

    char seguir='s';
    int opcion=0;int i;
    char title[20];
    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);



        switch(opcion)
        {
            case 1:
                peliculas[contadorPeliculas] = movie_newFull();
                contadorPeliculas++;
                break;
            case 2:
                movie_delete();
                break;
            case 3:
               printf("\n Ingrese titulo a modificar \n");
                fflush(stdin);
                scanf("%s",title);
                fflush(stdin);
                movie_modify(movie_search(peliculas,title));

               break;
            case 4:
                for(i=0;i<contadorPeliculas;i++){

                movie_pagina(peliculas[i]);
                }
               break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}






EMovie *movie_newFull(){

    EMovie *p = NULL;

p = (EMovie*)malloc(sizeof(EMovie)) ;

    if(p!= NULL){


printf("Ingrese titulo\n");
scanf("%s",p->titulo);
fflush(stdin);
printf("Ingrese descripcion\n");
scanf("%s",p->descripcion);
fflush(stdin);
printf("Ingrese genero\n");
scanf("%s",p->genero);
fflush(stdin);
printf("Ingrese link de la imagen\n");
scanf("%s",p->linkImagen);
fflush(stdin);
printf("Ingrese puntaje\n");
scanf("%d",&p->puntaje);
fflush(stdin);
printf("Ingrese duracion\n");
scanf("%d",&p->duracion);
fflush(stdin);
    }
    return p;
}


void movie_delete(){
printf("\n Ingrese titulo a borrar \n");
char title[20];
fflush(stdin);
scanf("%s",title);
fflush(stdin);
EMovie* pelicula= movie_search(peliculas,title);
if(pelicula!=NULL){
free((void*)pelicula);
printf("\n borrada\n");
}else{
printf("\nNo encontrada\n");}
return;
}




int movie_pagina(EMovie * pelicula){

    char cadena1 [] = "<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='\n";
    char cadena2 [] = "'alt=''></a><h3><a href='#'>\n";
    char cadena3 [] = "</a></h3><ul><li>Género:";
    char cadena4 [] = "</li><li>Puntaje:";
    char cadena5 [] = "</li><li>Duración:";
    char cadena6 [] = "</li></ul><p>";
    char cadena7 [] = "</p></article>";

    FILE* fichero;
    char html[] = ".html";

        char *concatenacion = (char*) malloc(strlen(pelicula->titulo)+strlen(html)+1);//+1 for the zero-terminator
    strcpy(concatenacion, pelicula->titulo);
    strcat(concatenacion, html);

    fichero = fopen( concatenacion , "wt");


    fputs(cadena1, fichero);
    fputs(pelicula->linkImagen, fichero);
    fputs(cadena2, fichero);
    fputs(pelicula->titulo, fichero);
    fputs(cadena3, fichero);
    fputs(pelicula->genero, fichero);
    fputs(cadena4, fichero);
    fputs(pelicula->puntaje, fichero);
    fputs(cadena5, fichero);
    fputs(pelicula->duracion, fichero);
    fputs(cadena6, fichero);
    fputs(pelicula->descripcion, fichero);
    fputs(cadena7, fichero);

    fclose(fichero);
    printf("Proceso completado");


}



EMovie* movie_search(EMovie* pelicula[],char titulo[20]){
int i;
EMovie *resultado = NULL;
for(i=0;i<contadorPeliculas;i++){

        if(strcmp((*(pelicula+i))->titulo,titulo)==0){

            resultado = *(pelicula+i);


        }

}
return resultado;

}

void movie_modify(EMovie *p){


    printf("Ingrese nuevo titulo\n");
scanf("%s",p->titulo);
fflush(stdin);
printf("Ingrese nueva descripcion\n");
scanf("%s",p->descripcion);
fflush(stdin);
printf("Ingrese nuevo genero\n");
scanf("%s",p->genero);
fflush(stdin);
printf("Ingrese link de la imagen\n");
scanf("%s",p->linkImagen);
fflush(stdin);
printf("Ingrese puntaje\n");
scanf("%d",&p->puntaje);
fflush(stdin);
printf("Ingrese duracion\n");
scanf("%d",&p->duracion);
fflush(stdin);
    ;
}
