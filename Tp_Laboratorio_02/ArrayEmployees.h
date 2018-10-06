#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED



typedef struct
    {
        int id;
        char name[51];
        char lastName[51];
        float salary;
        int sector;
        int isEmpty;

    }sEmployee;

/** \brief
*
* \param
* \param
* \return
*
*/
int options();

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


int addEmployees(sEmployee* list, int len, int id, char name[], char lastName[], float salary, int sector);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int searchEmpty(sEmployee* list, int len);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int printEmployees(sEmployee* list, int len);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int findEmployeeById(sEmployee* list, int len, int id);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void modifyEmployee(sEmployee* list, int len);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int sortEmployees(sEmployee* list, int len, int order);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int removeEmployee(sEmployee* list, int len);
float  salaryAverage(sEmployee* list, int len);
int  aboveAverage(sEmployee* list, int len);
float  totalSalary(sEmployee* list, int len);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void getString(char* message,char* input);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
char getChar(char* message);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int esNumerico(char* str);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int getStringLetras(char* message,char* input);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int getStringNumeros(char* message,char* input);



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void harcodeoEmployee(sEmployee* list);

#endif // ARRAYEMPLOYEES_H_INCLUDED
