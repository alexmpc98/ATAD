#include "student.h"
#include "grade.h"
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Cria essencialmente uma nota de um estudante
 * 
 * @param number Numero de Estudante
 * @param name Nome do Estudante
 * @param result Nota do Estudante
 * @return Grade 
 */
Grade gradeCreate(int number, char* name, float result){
    Student newStudent;
    Grade newGrade;
    if(result >= 0 && result < 21){
        newStudent.studentNumber = number;
        newStudent.name = name;
        newGrade.student = newStudent;
        newGrade.result = result;
        return newGrade;
    }
    else{
        printf("Nota inserida não se encontra nos parametros necessários, será declarado 0\n");
        newStudent.studentNumber = number;
        newStudent.name = name;
        newGrade.student = newStudent;
        newGrade.result = 0;
        return newGrade;
    }
}

/**
 * @brief Retorna ao utilizador se o estudante está aprovado ou reprovado
 * 
 * @param result Nota do Estudante
 * @return char 
 */
char* Approvation(float result){
    if(result >= 9.5){
            return "Approved";
    }
    else{
            return "Reproved";
    }
}
/**
 * @brief Mostra ao utilizador a nota de um estudante
 * 
 * @param g Nota do estudante
 */

void gradePrint(Grade g){
    printf("Number: %d | Name: %s | Grade: %.2f | Status: %s \n\n",
    g.student.studentNumber,g.student.name,g.result, Approvation(g.result));
}

/**
 * @brief Mostra ao utilizador uma lista de notas de estudantes
 * 
 * @param gradeArr Array de Notas
 * @param size Tamanho do Array
 */
void gradeArrayPrint(Grade *gradeArr,int size){
    for(int i=0; i<size;i++){
        printf("Number: %d | Name: %s | Grade: %.2f | Status: %s \n",gradeArr[i].student.studentNumber,
        gradeArr[i].student.name,gradeArr[i].result, Approvation(gradeArr[i].result));
    }
}

/**
 * @brief Retorna o número de alunos aprovados na turma
 * 
 * @param GradeArr Array de Notas
 * @param size Tamanho do Array
 * @return int 
 */
int getNumberApproved(Grade *GradeArr,int size){
    int count = 0;
    for(int i=0; i<size; i++){
        if(Approvation(GradeArr[i].result) == "Approved"){
            count++;
        }
    }
    return count;
}


/**
 * @brief Retorna se o valor procurado, existe nas notas dos alunos
 * 
 * @param gradeArr Array de Notas
 * @param size Tamanho do Array
 * @param value Valor a procurar
 * @return Boolean 
 */
bool resultExists(Grade *gradeArr, int size, float value){
    for(int i=0; i<size; i++){
        if(gradeArr[i].result == value){
            return true;
        }
    }
    return false;
}

/**
 * @brief Obtenção da nota mais alta 
 * 
 * @param gradeArr Array de Notas
 * @param size Tamanho do Array
 * @return int 
 */
int getMajorGrade(Grade *gradeArr,int size){
    float biggestGrade = gradeArr[0].result;
    int position = 0;
    
    if(size == 0){
        return -1;
    }

    for(int i=0;i<size;i++){
        if(gradeArr[i].result > biggestGrade){
            biggestGrade = gradeArr[i].result;
            position = i;
        }
    }
    return position;
}

/**
 * @brief Obtenção da nota mais baixa
 * 
 * @param gradeArr Array de Notas
 * @param size Tamanho do Array
 * @return int 
 */
int getMinorGrade(Grade *gradeArr,int size){
    float lowestGrade = gradeArr[0].result;
    int position = 0;
    
    if(size == 0){
        return -1;
    }

    for(int i=0;i<size;i++){
        if(gradeArr[i].result < lowestGrade){
            lowestGrade = gradeArr[i].result;
            position = i;
        }
    }
    return position;
}

/**
 * @brief Demonstração de informações sobre um conjunto de notas
 * 
 * @param gradeArr Array de Notas
 * @param size Tamanho do Array
 * @return int 
 */
void gradeArrayStats(Grade *gradeArr,int size){
    gradeArrayPrint(gradeArr,size);

    int Approved = getNumberApproved(gradeArr,size);
    printf("Total of Approved: %d in %d\n", Approved,size);

    int majorGrade = getMajorGrade(gradeArr,size);
    printf("The best great is %.2f values from %s\n",
    gradeArr[majorGrade].result, gradeArr[majorGrade].student.name);

    int minorGrade = getMinorGrade(gradeArr,size);
    printf("The worst great is %.2f values from %s\n", 
    gradeArr[minorGrade].result, gradeArr[minorGrade].student.name);
}

/**
 * @brief Organização do array por notas com selection sort
 * 
 * @param gradeArr Array de Notas
 * @param size Tamanho do Array
 */
void gradeArrSortByResult(Grade *gradeArr,int size){
    Grade newGrade;
    for(int i=0; i<size-1;i++){
        for(int j=i+1; j<size;j++){
            if(gradeArr[i].result > gradeArr[j].result){
                newGrade = gradeArr[i];
                gradeArr[i] = gradeArr[j];
                gradeArr[j] = newGrade;
            }
        }
    }
    gradeArrayPrint(gradeArr,size);   
}

/**
 * @brief Organização do array com bubble sort
 * 
 * @param gradeArr Array de Notas
 * @param size Tamanho do Array
 */
void gradeArrSortByNumber(Grade *gradeArr,int size){
    int newNumber = 0;
    for(int i=0;i<size;i++){
        for(int a=0; a < size - i - 1; a++){
            if(gradeArr[a].student.studentNumber > gradeArr[a+1].student.studentNumber){
                newNumber = gradeArr[a].student.studentNumber;
                gradeArr[a].student.studentNumber = gradeArr[a+1].student.studentNumber;
                gradeArr[a+1].student.studentNumber = newNumber;
            }
        }
    }
    gradeArrayPrint(gradeArr,size);
}
