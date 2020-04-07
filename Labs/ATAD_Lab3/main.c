#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include "student.h"
#include "grade.h"

int main(){
    char* name = "Alex";
    char * names[10] = {"Hugo Vieira", "Maria Carvalho", "Joaquim Dinis", "Henrique Ferreira",
    "Margarida Mourato", "Diogo Carreira","Ana Marques", "Manuel Quintino", "Joana Firmino", "Lara Pires"};
    
    const int studentNumbers[10] = {145678478,193498649,190530864,156978458,146978478,185678478,
    175678458,135674468,145678479,165678478};

    const float results[10] = {
    10.40,16.35,09.50,17.40,06.45,12.80,14.60,07.20,16.40,19.30};

    Grade GradeVector[10];
    Grade newGrade;
    Student newStudent;
    newStudent = studentCreate(190221093,name);
    newGrade = gradeCreate(190221093,name,20);
    gradePrint(newGrade);

    for(int i=0; i<10;i++){
        GradeVector[i] = gradeCreate(studentNumbers[i],names[i],results[i]);  
    }

    gradeArrayPrint(GradeVector,10);
    int Approved = getNumberApproved(GradeVector,10);
    printf("Total of Approved: %d in 10\n", Approved);

/* Result Exists */
/*
    float value = 7.20;
    bool ResultExists = resultExists(GradeVector,10,value);
    printf("Someone got %.2f values? ", value);
    printf(ResultExists ? "Yes\n" : "No\n");
*/


    int majorGrade = getMajorGrade(GradeVector,10);
    printf("The best great is %.2f values from %s\n", results[majorGrade], names[majorGrade]);

    int minorGrade = getMinorGrade(GradeVector,10);
    printf("The worst great is %.2f values from %s\n", results[minorGrade], names[minorGrade]);

    gradeArrayStats(GradeVector,10);

    printf("\nSort all grades by results:\n");
    printf("All class notes:\n");
    gradeArrSortByResult(GradeVector,10);

    printf("\nSort all grades by student number:\n");
    printf("All class notes:\n");
    gradeArrSortByNumber(GradeVector,10);
}
