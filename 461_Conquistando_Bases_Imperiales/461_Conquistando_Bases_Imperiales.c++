/*
50 10 5
20 20 15
40 20 10


20 10 15
50 40 20

*/
struct bases
{
    int conquistar;
    int mueren;
    int dejar;
    int necesarios;
    int utiles;
    bases(int conq, int mor, int dej){
        conquistar = conq;
        mueren = mor;
        dejar = dej;
        necesarios = conquistar + dejar;
        utiles = conquistar - mueren - dejar;
    }
};
/*
    Declaro variables soldados usados= 0; y soldados restantes = 0;

    Creo que hay que ordenar por soldados útiles, pero no lo tengo tan claro

    Eliges el primero, sumas a soldados usados los necesarios para conquistar

    Si los soldados utiles son positivos se suman a la variable soldados restantes
        Si no se suman a los soldados usados con valor absoluto

    Siguiente iteracion:

    Eliges el siguiente, le restas tanto a los soldados para conquistar como a los soldados muertos el valor de los soldados restantes

    Calculas la diferencia con los nuevos valores

    Sumas el valor a la variable de soldados usados los soldados necesarios para conquistar

    Si los soldados utiles son positivos se suman a la varaible soldados restantes
        Si o se suman a los soldados usados con valor absoluto

    Siguiente iteracion: ...

    ...
*/
