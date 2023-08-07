#include "ColaDeDesastres.h"
#include "PilaDeDesastres.h"


void completaDatos (PilaDeDesastres *p, desastre *d);


int main()
{
    int cuantosDesastres, fecha, victimas, anteriorFecha,i;
    ColaDeDesastres c;
    PilaDeDesastres p;
    nuevaColaDeDesastres(&c);
    nuevaPila(&p);
    desastre d;
    meterFecha(0,&d);
    meterVictimas(0,&d);
    apilar(&p,d);
    anteriorFecha = 0;
    printf("Cuantos desastres han sucedido?: ");
    scanf("%d", &cuantosDesastres);
    while(cuantosDesastres < 0)
    {
        printf("Imposible, pruebe de nuevo. ");
        printf("Cuantos desastres han sucedido?: ");
        scanf("%d", &cuantosDesastres);
    }
    if (cuantosDesastres == 0)
        exit(1);
    printf("Introduzca los datos de los desastres, en orden cronológico\n");
    //mete datos en la cola
    for (i = 0; i < cuantosDesastres; i++)
    {
        printf("%d)¿En qué fecha fue?: ", i+1);
        scanf("%d", &fecha);
        while (anteriorFecha > fecha)
        {
            printf("En orden cronologico, por favor. ");
            printf("¿En qué fecha fue?: ");
            scanf("%d", &fecha);
        }
        anteriorFecha = fecha;
        meterFecha(fecha, &d);
        printf("¿Cuántas personas murieron?: ");
        scanf("%d", &victimas);
        meterVictimas(victimas, &d);
        //comparo desastre actual con los anteriores hasta que haya uno mayor y guardo su fecha, o hasta que no haya mas y guardo un 0
        //apilo el accidente si mas pequeño que cima y mientras sea mayor: desapilo y apilo desastre
        completaDatos(&p,&d);
        pideTurnoColaDeDesastres(&c,d);
    }
    printf("Estos son los desastres que has introducido\n");
    //saca datos por pantalla
    for (i = 0; i < cuantosDesastres; i++)
    {
        primeroColaDeDesastres (c, &d);
        avanceColaDeDesastres(&c);
        printf("%d ) En %d murieron %d personas, el último desastre mayor fue en %d\n", i+1,cuandoFue(d), cuantasVictimas(d), ultimoMayor(d));
    }
    return 0;
}

void completaDatos (PilaDeDesastres *p, desastre *d)
{
    while(!esNulaPila(*p) && (cuantasVictimas(cima(*p)) <= cuantasVictimas(*d)))
        desapilar(&(*p));
    if (!esNulaPila(*p))
        d->ultimoMasMuertos = cuandoFue(cima(*p));
    else
        d->ultimoMasMuertos = 0;
    apilar(&(*p),*d);
    return;
}
