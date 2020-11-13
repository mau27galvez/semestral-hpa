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
    char id[50];
    char name[100];
    char faculty[50];
} PROFESSOR;

typedef struct
{
    char id[50];
    char car_id[50];
    char profesor_id[50];
} PARKING_SLOT;

int InsertCar( CAR car );
int InsertProfessor( PROFESSOR professor );
int InsertParkingSlot( PARKING_SLOT parking_slot );

CAR *GetCar();
PROFESSOR *GetProfessor();
PARKING_SLOT *GetParkingSlot();

int main()
{
    CAR *cars = GetCar();
    PROFESSOR *professors = GetProfessor();
    PARKING_SLOT *parking_slots = GetParkingSlot();
    printf("%s\n", cars[0].type);
    printf("%s\n", professors[0].name);
    printf("%s\n", parking_slots[0].id);

    return 0;
}

int InsertCar( CAR car )
{
    FILE *out = fopen( CAR_TABLE, "r" );

    if ( !(out = fopen( CAR_TABLE, "a" )) ) {
        printf("No se puede escribir en el archivo %s\n", CAR_TABLE);

        return -1;
    }

    fprintf(out, "%s,%s,%s", car.id, car.type, car.color);
    fputs("\n", out);
    printf("Registro guardado!\n");

    fclose(out);

    return 0;
}

int InsertProfessor( PROFESSOR professor )
{
    FILE *out = fopen( PROFESSOR_TABLE, "r" );

    if ( !(out = fopen( PROFESSOR_TABLE, "a" )) ) {
        printf("No se puede escribir en el archivo %s\n", PROFESSOR_TABLE);

        return -1;
    }

    fprintf(out, "%s,%s,%s", professor.id, professor.name, professor.faculty);
    fputs("\n", out);
    printf("Registro guardado!\n");

    fclose(out);

    return 0;
}

int InsertParkingSlot( PARKING_SLOT parking_slot )
{
    FILE *out = fopen( PARKING_SLOT_TABLE, "r" );

    if ( !(out = fopen( PARKING_SLOT_TABLE, "a" )) ) {
        printf("No se puede escribir en el archivo %s\n", PARKING_SLOT_TABLE);

        return -1;
    }

    fprintf(out, "%s,%s,%s", parking_slot.id, parking_slot.car_id, parking_slot.profesor_id);
    fputs("\n", out);
    printf("Registro guardado!\n");

    fclose(out);

    return 0;
}

CAR *GetCar()
{
    FILE *out = fopen( CAR_TABLE, "r" );
    char row[500];
    CAR *cars = NULL;
    char *delim = ",";
    int carsListSize = 0;

    while ( fgets( row, 500, out ) != NULL ) {
        int column = 1;

        if ( !cars ) {
            cars = malloc( sizeof( CAR ) );

            char *ptr = strtok(row, delim);

            while( ptr != NULL )
            {
                switch ( column ) {
                    case 1:
                        strcpy( cars[ carsListSize ].id, ptr );
                        break;
                    case 2:
                        strcpy( cars[ carsListSize ].type, ptr );
                        break;
                    case 3:
                        strcpy( cars[ carsListSize ].color, ptr );
                        break;
                }

                ptr = strtok(NULL, delim);
                column++;
            }
        } else {
            cars = realloc( cars, sizeof( CAR ) * ( carsListSize + 1 ) );

            char *ptr = strtok(row, delim);

            while( ptr != NULL )
            {
                switch ( column ) {
                    case 1:
                        strcpy( cars[ carsListSize ].id, ptr );
                        break;
                    case 2:
                        strcpy( cars[ carsListSize ].type, ptr );
                        break;
                    case 3:
                        strcpy( cars[ carsListSize ].color, ptr );
                        break;
                }

                ptr = strtok(NULL, delim);
                column++;
            }
        }

        carsListSize++;
    }

    return cars;
}

PROFESSOR *GetProfessor()
{
    FILE *out = fopen( PROFESSOR_TABLE, "r" );
    char row[500];
    PROFESSOR *professors = NULL;
    char *delim = ",";
    int professorsListSize = 0;

    while ( fgets( row, 500, out ) != NULL ) {
        int column = 1;

        if ( !professors ) {
            professors = malloc( sizeof( PROFESSOR ) );

            char *ptr = strtok(row, delim);

            while( ptr != NULL )
            {
                switch ( column ) {
                    case 1:
                        strcpy( professors[ professorsListSize ].id, ptr );
                        break;
                    case 2:
                        strcpy( professors[ professorsListSize ].name, ptr );
                        break;
                    case 3:
                        strcpy( professors[ professorsListSize ].faculty, ptr );
                        break;
                }

                ptr = strtok(NULL, delim);
                column++;
            }
        } else {
            professors = realloc( professors, sizeof( PROFESSOR ) * ( professorsListSize + 1 ) );

            char *ptr = strtok(row, delim);

            while( ptr != NULL )
            {
                switch ( column ) {
                    case 1:
                        strcpy( professors[ professorsListSize ].id, ptr );
                        break;
                    case 2:
                        strcpy( professors[ professorsListSize ].name, ptr );
                        break;
                    case 3:
                        strcpy( professors[ professorsListSize ].faculty, ptr );
                        break;
                }

                ptr = strtok(NULL, delim);
                column++;
            }
        }

        professorsListSize++;
    }

    return professors;
}

PARKING_SLOT *GetParkingSlot()
{
    FILE *out = fopen( PROFESSOR_TABLE, "r" );
    char row[500];
    PARKING_SLOT *parking_slots = NULL;
    char *delim = ",";
    int parking_slotsListSize = 0;

    while ( fgets( row, 500, out ) != NULL ) {
        int column = 1;

        if ( !parking_slots ) {
            parking_slots = malloc( sizeof( PROFESSOR ) );

            char *ptr = strtok(row, delim);

            while( ptr != NULL )
            {
                switch ( column ) {
                    case 1:
                        strcpy( parking_slots[ parking_slotsListSize ].id, ptr );
                        break;
                    case 2:
                        strcpy( parking_slots[ parking_slotsListSize ].car_id, ptr );
                        break;
                    case 3:
                        strcpy( parking_slots[ parking_slotsListSize ].profesor_id, ptr );
                        break;
                }

                ptr = strtok(NULL, delim);
                column++;
            }
        } else {
            parking_slots = realloc( parking_slots, sizeof( PROFESSOR ) * ( parking_slotsListSize + 1 ) );

           char *ptr = strtok(row, delim);

            while( ptr != NULL )
            {
                switch ( column ) {
                    case 1:
                        strcpy( parking_slots[ parking_slotsListSize ].id, ptr );
                        break;
                    case 2:
                        strcpy( parking_slots[ parking_slotsListSize ].car_id, ptr );
                        break;
                    case 3:
                        strcpy( parking_slots[ parking_slotsListSize ].profesor_id, ptr );
                        break;
                }

                ptr = strtok(NULL, delim);
                column++;
            }
        }

        parking_slotsListSize++;
    }

    return parking_slots;
}
