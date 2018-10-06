#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define LEN 1000
#define OK 0
#define ERROR -1




int main()
{
    int r;
    int id = 0000;
    char name[51];
    char lastName[51];
    int  salary;
    int sector;
    int aux;
    char auxCharSector[51];
    char auxCharSalary[51];
    int firstEmployee = 0;

    sEmployee employees[LEN];

    initEmployees(employees, LEN);
    /** harcodeoEmployee(employees); **/
    char exit = 'n';
    do{
        switch(options())
        {
            case 1:
                    if(searchEmpty(employees, LEN) == 0)
                    {

                        fflush(stdin);
                        if(!getStringLetras("Ingrese Nombre : ", name))
                        {
                            printf("\nEl nombre debe contener solo letras\n");
                            system("pause");
                            break;
                        }
                        fflush(stdin);
                        if(!getStringLetras("\nIngrese Apellido : ", lastName))
                        {
                            printf("\nEl apellido debe contener solo letras\n");
                            system("pause");
                            break;
                        }

                        fflush(stdin);
                        if(!getStringNumeros("\nIngrese Salario : ", auxCharSalary))
                        {
                            printf("\nEl salario debe contener solo numeros\n");
                            system("pause");
                            break;
                        }

                        fflush(stdin);
                        if(!getStringNumeros("\nIngrese Sector : ", auxCharSector))
                        {
                            printf("\nEl sector debe contener solo numeros\n");
                            system("pause");
                            break;
                        }
                        salary = atoi(auxCharSalary);
                        sector = atoi(auxCharSector);

                        r = addEmployees(employees, LEN, id, name, lastName, salary, sector);
                        firstEmployee = 1;
                        }
                        else
                        {
                        printf("\nESPACIO LLENO\n\n");
                        system("pause");
                        }

                    break;
            case 2:
                    if(firstEmployee == 0)
                    {
                        printf("Primero debe cargar un Empleado\n\n");
                        system("pause");
                    }
                    else
                    {
                        modifyEmployee(employees, LEN);
                    }
                    system("pause");
                    break;
            case 3:
                    if(firstEmployee == 0)
                    {
                        printf("Primero debe cargar un Empleado\n\n");
                        system("pause");
                    }
                    else
                    {
                        removeEmployee(employees, LEN);
                    }
                    system("pause");
                    break;
            case 4:
                    system("cls");
                    if(firstEmployee == 0)
                    {
                        printf("Primero debe cargar un Empleado\n\n");
                        system("pause");
                    }
                    else
                    {
                        sortEmployees(employees, LEN, 1);/** Orden 0 Descendente, 1 Ascendente**/
                        printEmployees(employees, LEN);
                        printf("\nEl total de salarios es de %.2f\n", totalSalary(employees, LEN));
                        printf("\nEl promedio de salarios es de %.2f\n", salaryAverage(employees, LEN));
                        printf("\nLos empleados que tienen salario por ensima de la media son %d\n", aboveAverage(employees, LEN));
                        system("pause");
                    }

                    break;
            case 5:
                    printf("Salir\n\n");
                    system("pause");
                    exit = 's';
                    break;
        }
      }while(exit=='n');






    return 0;
}




