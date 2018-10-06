#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define LEN 1000
#define OK 0
#define ERROR -1

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int options()
{
    int option;

    system("cls");
    printf("\n*** Menu de Opciones ***\n\n");
    printf("\n    1- Altas\n");
    printf("\n    2- Modificar\n");
    printf("\n    3- Baja\n");
    printf("\n    4- Informar\n");
    printf("\n    5- Salir\n");
    printf("\n\n** Ingrese Opcion **\n");
    scanf("%d", &option);

    return option;
}



int initEmployees(sEmployee* list, int len)
{
    int r = ERROR;
    if(list != NULL && len > 0)
    {
    for(int i = 0; i < len; i++)
    {
        list[i].isEmpty = 1;
        r = OK;
    }
    }
    else
    {
        r = ERROR;
    }
    return r;
}



int searchEmpty(sEmployee* list, int len)
{
    int r = ERROR;
    for(int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            r = i;
            break;
        }
    }
    return r;
}




int addEmployees(sEmployee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int r = ERROR;
    if((list != NULL) && (len > 0))
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                list[i].id = id + 1;
                strcpy(list[i].name, name);
                strcpy(list[i].lastName, lastName);
                list[i].salary = salary;
                list[i].sector = sector;
                list[i].isEmpty = 0;
                r = OK;
                break;
            }
        }
    }

    return r;
}



int printEmployees(sEmployee* list, int len)
{
    system("cls");
    int r = ERROR;
    if(len > 0)
    {
        printf("\n\nID    Name    Last    Name    Salary    Sector\n");
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                fflush(stdin);
                printf("%d     %s     %s     %f     %d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
            }
        }
        printf("\n\n");
        r = OK;
    }

    return r;
}



int findEmployeeById(sEmployee* list, int len, int id)
{
    int r = ERROR;

    for(int i = 0; i < len; i++)
    {
        if((list[i].isEmpty == 0)&&(list[i].id == id))
        {
            r = i; /** LE ASIGNO LA POSICION  ENCONTRADA Y SALGO **/
            break;
        }
    }
    return r;
}




int removeEmployee(sEmployee* list, int len)
{
    int r = ERROR;
    int id;
    char answer;

    system("cls");
    printf("***  Baja Empleado  ***\n\n");

    printf("Ingrese id: ");
    scanf("%d", &id);
    r = findEmployeeById(list, len, id);

    if(r == ERROR)
    {
        printf("No hay empleados con el id %d\n\n", id);
        system("pause");
    }
    else
    {
        printf("Confirma baja s/n : ");
        fflush(stdin);
        scanf("%c", &answer);

        if(answer == 'n')
        {
            printf("\nBaja cancelada");
        }
        else
        {
            list[r].isEmpty = ERROR; /** SE LE ASIGNA EL VALOR 1 PARA CAMBAIR SU ESTA DE LLENO(0)A VACIO**/
            printf("Baja exitosa\n\n");
        }
    system("pause");
    }
    return OK;
}



int sortEmployees(sEmployee* list, int len, int order)
{
    sEmployee auxEmployee;
    int i, j;
    for(i = 0; i < len-1; i++)
    {
        for(j = i+1; j < len; j++)
        {
           if(order == 1)
            { /** ascendente **/
            if(((strcmp(list[i].lastName, list[j].lastName)>0))&&(list[i].sector > list[j].sector))
            {
                auxEmployee = list[j];
                list[j] = list[i];
                list[i] = auxEmployee;
            }
            }
            else if(order == 0) /** decendente**/
            {
                if(((strcmp(list[i].lastName, list[j].lastName)<0))&&(list[i].sector < list[j].sector))
            {
                auxEmployee = list[j];
                list[j] = list[i];
                list[i] = auxEmployee;

            }
            }

        }
    }
    return OK;
}



void modifyEmployee(sEmployee* list, int len)
{

    int index;
    int id;
    char answer;
    char newName[51];
    char newLastName[51];
    float newSalary;
    int newSector;


    system("cls");
    printf("***  Modificar Empleado  ***\n\n");

    printf("Ingrese id: ");
    scanf("%d", &id);

    index = findEmployeeById(list, len, id);

    if(index == -1)
    {
        printf("No hay empleados con id %d\n\n", id);
        system("pause");
    }
    else
    {

        printf("Dar de baja id %d",list[index], len);
        int option;
        printf("¿ Que desea modificar ?\n");
        printf("1- Nombre\n2- Apellido\n3- Salario\n4- Sector\n\n");
        fflush(stdin);
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                    printf("¿ Modificar nombre ? s/n: ");
                    fflush(stdin);
                    scanf("%c", &answer);

                    if(answer == 'n')
                    {
                        printf("\nModificacion de nombre cancelada\n\n");
                    }
                    else
                    {
                        printf("Ingrese nuevo nombre: \n");
                        fflush(stdin);
                        gets(newName);
                        strcpy(list[index].name, newName);

                        printf("\nModificacion de nombre exitosa");
                    }
                    break;

            case 2:
                    printf("¿ Modificar apellido ? s/n: ");
                    fflush(stdin);
                    scanf("%c", &answer);

                    if(answer == 'n')
                    {
                        printf("\nModificacion de apellido cancelada\n\n");
                    }
                    else
                    {
                        printf("Ingrese nuevo apellido: \n");
                        fflush(stdin);
                        gets(newLastName);
                        strcpy(list[index].lastName, newLastName);

                        printf("\nModificacion de apellido exitosa");
                    }
                    break;

            case 3:
                    printf("¿ Modificar salario ? s/n: ");
                    fflush(stdin);
                    scanf("%c", &answer);
                    if(answer == 'n')
                    {
                        printf("\nModificacion de salario cancelada\n\n");
                    }
                    else
                    {
                        printf("Ingrese nuevo salario: \n");
                        scanf("%f", &newSalary);
                        list[index].salary = newSalary;

                        printf("\nModificacion de salario exitosa");
                    }
                    break;

            case 4:
                    printf("¿ Modificar sector ? s/n: ");
                    fflush(stdin);
                    scanf("%c", &answer);
                    if(answer == 'n')
                    {
                        printf("\nModificacion de sector cancelada\n\n");
                    }
                    else
                    {
                        printf("Ingrese nuevo sector: \n");
                        fflush(stdin);
                        scanf("%d", &newSector);
                        list[index].sector = newSector;

                        printf("\nModificacion de sector exitosa");
                    }
                    break;

    system("pause");
    }
    }
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char* message, char* input)
{
    printf("%s", message);
    scanf ("%s", input);
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char* message)
{
    char auxiliar;
    printf("%s",message);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}


/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char* str)
{
   int i = 0;
   while(str[i] != '\0')
   {
       if((str[i] > '0' )&&(str[i] < '9'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char* str)
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char* message ,char* input)
{
    int r = OK;
    char aux[256];
    getString(message,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        r = ERROR;
    }

    return r;
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char* message ,char* input)
{
    int r = ERROR;
    char aux[256];
    getString(message,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        r = OK;
    }

    return r;
}


void harcodeoEmployee(sEmployee* list)
{

    sEmployee x[]={
    {1111,"Juan","Perez",20000, 1},
    {1112,"Pedro","Picas",30000, 3},
    {1113,"Juana","Luquez",18000, 1},
    {1114,"Ana","Puertas",20000, 2},
    {1115,"Sara","Casas",30000, 3}
    };
    for(int i = 0; i< 5;i++)
    {
        list[i] = x[i];
    }
}



float  salaryAverage (sEmployee* list, int len)
{
    int accountantSalary = 0 ;
    float accumulatorSalary = 0 ;
    float average;
    for( int i = 0 ; i < len; i ++)
    {

        if(list[i].isEmpty == 0)
        {
            accumulatorSalary += list[i].salary ;
            accountantSalary++;
        }
    }
    average = (accumulatorSalary / accountantSalary);
    return average;

}



int  aboveAverage(sEmployee* list, int len)
{
     int accountant = 0 ;

    for(int i = 0 ; i < len; i++)
    {
        if((list[i].isEmpty == 0)&&(list[i].salary > salaryAverage(list, len)))
        {
            accountant++;
        }
    }
    return accountant;
}



float  totalSalary(sEmployee* list, int len)
{
    float accumulatorSalary = 0;
    for(int i = 0; i < len; i++)
    {
        if (list[i].isEmpty == 0)
        {
            accumulatorSalary += list[i].salary;
        }
    }

    return accumulatorSalary;
}
