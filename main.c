
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <conio.h>


void cargarPila(Pila *p, int cant)
{

    srand(time(NULL));
    for ( int i =0; i <cant ; i++)
        apilar(p,rand()%10);



}
//----------------------------------------------------------------------------------------------------------------------------
void pasarPila(Pila *p, Pila *q)
{
    while(!pilavacia(p))
    {
        apilar(q,desapilar(p));
    }
}

//-------------------------------------------------------------------------------------------------------------------------------

void pasarElementosEnMismoOrden(Pila *p, Pila *q)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(p))
    {
        apilar(&aux,desapilar(p));
    }
    while(!pilavacia(&aux))
    {
        apilar(q,desapilar(&aux));
    }

}

//------------------------------------------------------------------------------------------------------------------------------
int menorElementoDePila(Pila *p)
{
    Pila aux,menor;
    inicpila(&aux);
    inicpila(&menor);

    apilar(&menor,desapilar(p));
    while(!pilavacia(p))
    {
        if (tope(p) < tope(&menor))
        {
            apilar(&aux,desapilar(&menor));
            apilar(&menor,desapilar(p));
        }
        else
        {
            apilar(&aux,desapilar(p));
        }


    }
    while(!pilavacia(&aux))
    {
        apilar(p,desapilar(&aux));
    }

    return tope(&menor);

}
//-------------------------------------------------------------------------------------------------------------------------------------
void ordenamientoPorSeleccion(Pila *p, Pila *q)

{

    while(!pilavacia(p))
    {
        apilar(q,menorElementoDePila(p));

    }
}

//--------------------------------------------------------------------------------------------------------------------------

void insertarElementoAPila(Pila *p, int dato) // ESTA FUNCION ESTA BIEN Y ANDA PORQUE YA TENGO ORDENADA LA PILA

{
    Pila aux;
    inicpila(&aux);


    while(!pilavacia(p) && (tope (p) > dato))    //IMPORTANTE RESPETAR LOS PARENTESIS DEL TOPE. SINO NO ANDA
    {
        apilar (&aux,desapilar(p));

    }
    apilar(p,dato);

    {
        while(!pilavacia(&aux))
        {
            apilar(p,desapilar(&aux));
        }
    }


}


//-----------------------------------------------------------------------------------------------------------------------------

void ordenamientoPorInsercion(Pila *p, Pila *q)

{
    while(!pilavacia(p))
    {

        insertarElementoAPila(q,desapilar(p));  //UTILIZO LA FUNCION DE INSERTAR.

    }
}

//-------------------------------------------------------------------------------------------------------------------------------

int sumaDeTopes(Pila p)
{
    Pila aux;
    inicpila(&aux);
    int suma=0;

    apilar(&aux,desapilar(&p));

    suma = tope(&aux) + tope(&p);

    return suma;


}

//-------------------------------------------------------------------------------------------------------------------------------

int sumaPila(Pila *p)
{
    int suma=0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(p))
    {

        apilar(&aux,desapilar(p));
        suma=suma+tope(&aux);

    }
    while(!pilavacia(&aux))
    {
       apilar(p,desapilar(&aux));
    }
    return suma;
}

//-----------------------------------------------------------------------------------------------------------------------
int contadorPila(Pila *p)

{
    int cont=0;
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(p))
    {
        apilar(&aux,desapilar(p));
        cont++;
    }
    while(!pilavacia(&aux))
    {
        apilar(p,desapilar(&aux));
    }
    return cont;
}

//---------------------------------------------------------------------------------------------------------------------------

float divisionTotal(int p, int q)

{
    float division;

    division= (float)p/q;

    return division;
}

//-----------------------------------------------------------------------------------------------------------------------------

float promedioPila(Pila *p)
{
    int cont=0;
    int suma=0;
    float division=0;

    suma=sumaPila(p);
    cont=contadorPila(p);
    division=divisionTotal(suma,cont);
    return division;

}

//---------------------------------------------------------------------------------------------------------------------------------
int soloDigito(Pila *p)
{
    Pila aux;
    inicpila(&aux);
    int digito=0;
    int acumulador=0;
    int numConsante=10;
    int cont=0;


    while(!pilavacia(p))
    {
        apilar(&aux,desapilar(p));
    }
    while(!pilavacia(&aux))
    {

        digito=tope(&aux);
        acumulador+= tope(&aux)*pow(numConsante,cont);
        cont++;
         apilar(p,desapilar(&aux));
    }
    pasarPila(p,&aux);

    return acumulador;
}



int main()
{

    int opcion;
    char continuar='s';

    do
    {



        printf("Bienvenidos al sistema \n");

        printf("1- Cargar pila \n");
        printf("2-Pasar elementos de una pila a otra \n");
        printf("3- Pasar elementos conservando el orden \n");
        printf("4- Encontrar menor de una pila y eliminarlo\n");
        printf("5- Ordenacion por seleccion\n");
        printf("6- Insertar elemento \n");
        printf("7- Ordenacion por insercion \n ");
        printf("8- Sumar los dos primeros elementos de una pila \n");
        printf("9- Funcion que calcule el promedio de los elementos de una pila \n");
        printf("10- Funcion que reciba una pila con números de un solo dígito y que transforme esos dígitos en un número decimal \n");

        printf("Eliga una opcion \n");
        scanf("%d",&opcion);
        system("cls");
        switch(opcion)
        {

        case 1 :
        {
            //INICIALIZO PILA
            Pila dada;
            inicpila(&dada);
            //CARGO LA PILA
            cargarPila(&dada,10);
            //MUESTRO POR PANTALLA
            printf("Esta es la pila dada \n");
            mostrar(&dada);

            break;

        }

        case 2 :
        {
            //Hacer una función que pase todos los elementos de una pila a otra.

            Pila dada,aux;
            inicpila(&dada);
            inicpila(&aux);

            //CARGO PILA
            cargarPila(&dada,10);
            printf("Esta es la pila dada\n");
            mostrar(&dada);

            //PASO ELEMENTOS DE UNA PILA A OTRA

            pasarPila(&dada,&aux);

            //MUESTRO POR PANTALLA

            printf("Esta es la pila auxiliar con todos los elementos de dada \n");
            mostrar(&aux);


            break;


        }
        case 3 :
        {
            //Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.

            Pila dada,ordenada;
            inicpila(&dada);
            inicpila(&ordenada);

            //CARGO PILA
            cargarPila(&dada,10);
            //MUESTRO POR PANTALLA
            printf("Esta es la pila dada \n");
            mostrar(&dada);

            //LLAMO A LA FUNCION
            pasarElementosEnMismoOrden(&dada,&ordenada);

            //MUESTRO POR PANTALLA

            printf("Esta es la pila ordenada");
            mostrar(&ordenada);




            break;

        }

        case 4 :
        {
            //Hacer una función que encuentre el menor elemento de una pila y lo retorna.
            //La misma debe eliminar ese dato de la pila.

            Pila dada;
            inicpila(&dada);
            int menor;

            cargarPila(&dada,10);   //CARGO PILA
            printf("Esta es la pila dada con todos los valores \n");   //MUESTRO POR PANTALLA
            mostrar(&dada);

            //INICIALIZO FUNCION
            menor=menorElementoDePila(&dada);

            printf("Este es el menor elemento de la pila dada: %d \n ", menor);

            //MUESTRO COMO QUEDO LA PILA DADA

            printf("Esta es la pila dada sin el menor elemento \n");
            mostrar(&dada);


            break;


        }

        case 5 :

        {
            //Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.
            // Usar la función del ejercicio 4. (Ordenamiento por selección)

            Pila dada,ordenada;
            inicpila(&dada);
            inicpila(&ordenada);

            cargarPila(&dada,10);
            //MUESTRO POR PANTALLA
            printf("Esta es la pila dada \n");
            mostrar(&dada);

            //CARGO FUNCION DE ORDENAMIENTO

            ordenamientoPorSeleccion(&dada,&ordenada);
            printf("Esta es la pila ordenada");
            mostrar(&ordenada);



            break;



        }

        case 6 :
        {
            //Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta.

            int insertarElemento;
            Pila dada,ordenada;
            inicpila(&dada);
            inicpila(&ordenada);

            //LLAMO FUNCION PARA CARGAR LA PILA

            cargarPila(&dada,10);

            //MUESTRO POR PANTALLA

            printf("Esta es la pila dada \n");
            mostrar(&dada);


            //ORDENO LA PILA CARGADA

            ordenamientoPorSeleccion(&dada,&ordenada);
            printf("Esta es la pila ordenada");
            mostrar(&ordenada);

            //EL USUARIO DEBE INGRESAR UN ELEMENTO

            printf("Ingrese el elemento que desea insertar en la pila \n");
            scanf("%d",&insertarElemento);


            //UNA VEZ ORDENADA LA PILA LLAMO A LA FUNCION DE INSERTAR E INSERTO EL ELEMENTO
            insertarElementoAPila(&ordenada,insertarElemento);
            printf("Esta es la pila con el elemento insertado \n");
            mostrar(&ordenada);



            break;


        }

        case 7 :

        {
            //Ordenamiento por inserción

            Pila dada, ordenada;
            inicpila(&dada);
            inicpila(&ordenada);

            //CARGO PILA

            cargarPila(&dada,10);

            //MUESTRO POR PANTALLA
            printf("Esta es la pila dada \n");
            mostrar(&dada);


            //CARGO FUNCION DE ORDENAMIENTO POR INSERCION

            ordenamientoPorInsercion(&dada,&ordenada);

            printf("Esta es la pila ordenada por insercion \n");
            mostrar(&ordenada);




            break;

        }

        case 8 :

        {
            //Hacer una función que sume y retorne los dos primeros elementos de una pila (tope y anterior), sin alterar su contenido.

            Pila dada;
            inicpila(&dada);
            int suma;   //INICIALIZO VARIABLE PARA PODER IGUAL A LA FUNCION YA QUE ESTA NO ES VOID

            //LLAMO A LA FUNCION PARA CARGAR LA PILA
            cargarPila(&dada,10);
            printf("Esta es la pila dada \n");   //MUESTRO POR PANTALLA
            mostrar(&dada);

            //LLAMO A LA FUNCION
            suma=sumaDeTopes(dada); //NO UTILIZO AMPERSAND (&) PORQUE TRABAJE CON UNA FUNCION POR COPIA

            printf("Esta es la suma de los dos ultimos elementos de la pila dada : %d \n \n",suma);





            break;



        }

        case 9 :

            {
                //. Hacer una función que calcule el promedio de los elementos de una pila

                Pila dada;
                inicpila(&dada);
                float promedio;

                //CARGO Y MUESTRO LA PILA
                cargarPila(&dada,5);
                mostrar(&dada);



                promedio=promedioPila(&dada);
                printf("Este es el promedio de la pila dada %f \n \n",promedio);


                break;



                }


        case 10:

            {
               // Hacer una función que reciba una pila con números de un solo dígito
               // y que transforme esos dígitos en un número decimal.

                Pila dada;
                inicpila(&dada);
                int acum;

                //CARGO PILA


                cargarPila(&dada,5);
                printf("Esta es la pila dada");
                mostrar(&dada);

                //LLAMO A FUNCION
                acum= soloDigito(&dada);
                printf("Este es el numero final : %d \n \n", acum);




            }












        }

        printf("Desea volver al menu (s/n)\n");
        fflush(stdin);
        scanf("%c",&continuar);
        system("cls");


    }
    while(continuar=='s');







}
