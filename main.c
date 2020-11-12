/*
En los estacionamientos del edificio N°3 en el Campus Central de la UTP, existe un espacio
para ser alquilados a los docentes. La administración aplicar nuevas reglas y probar con un
prototipo de control para la venta de los espacios de estacionamientos. Existe disponibilidad
para 100 espacios y estos espacios se alquilarán semestralmente de acuerdo al tipo de auto
(Hatchback $15, Sedan $25, SUV $35 y Todoterreno $45). El prototipo debe almacenar la
información del auto y del docente; además, tener en cuenta un reporte de ventas.
(Funcionamiento para un semestre).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PARKING_SLOTS 100
#define HATCHBACK_PRICE 15
#define SEDAN_PRICE 15
#define SUV_PRICE 15
#define OFF_ROAD_PRICE 15

#define CAR_TABLE "cars.csv"
#define PROFESSOR_TABLE "professors.csv"
#define PARKING_SLOT_TABLE "parking-slots.csv"

typedef char CSVDATA[500];

typedef struct
{
    char id[50];
    char type[50];
    char color[50];
} CAR;

typedef struct
{
    char name[100];
    int id;
    int Faculty;
} PROFESSOR;

typedef struct
{
    int id;
    int car_id;
    int profesor_id;
} PARKING_SLOT;

int InsertCar( CAR car );
int InsertProfessor( PROFESSOR professor );
int InsertParkingSlot( PARKING_SLOT parking_slot );

int main()
{
    CAR car = {"1","SUV","red"};
    InsertCar( car );

    return 0;
}

int InsertCar( CAR car )
{
    FILE *out = fopen( CAR_TABLE, "r" );

    if ( !(out = fopen( CAR_TABLE, "w" )) ) {
        printf("No se puede escribir en el archivo %s\n", CAR_TABLE);

        return -1;
    }

    fprintf(out, "%s,%s,%s", car.id, car.type, car.color);
    fputs("\n", out);
    printf("Registro guardado!\n");

    fclose(out);

    return 0;
}
