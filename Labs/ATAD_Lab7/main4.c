#include <stdio.h>
#include <stdlib.h>
#include "kahoot.h"
#include "utils.h"
#include "list.h"
#include "listElem.h"


int getQuestions(PtList *listKR, int week);
void totalAverageScore(PtList *listKR);

int main(){
    PtList kr = NULL; 
    int week = 0;
    int a = 0;
    importKahootFromFile("kahootReports.csv",&kr);
    printf("Insert week number: ");
    scanf("%d",&week);
    a = getQuestions(&kr,week);
    printf("This week %d had %d questions\n",week,a);

    totalAverageScore(&kr);
}

/**
 * @brief Este algoritmo permite obter a quantidade de questões que existiram numa dada semana
 * 
 * @param listKR Lista que contem todos os dados previamente importados
 * @param week Semana que o utilizador deseja consultar
 *
 * @return int
 */
int getQuestions(PtList *listKR, int week){
    int ptSize = 0;  
    int size_code = listSize(*listKR,&ptSize);
    if(size_code == LIST_FULL || size_code == LIST_INVALID_RANK || size_code == LIST_NO_MEMORY
    || size_code == LIST_NULL){
        printf("An error ocurred... Please try again...\n");
        return -1;
    }
    KahootReport kr;
    int counter = 0;
    for(int i=0; i<ptSize;i++){
         listGet(*listKR,i,&kr);
         if(kr.week == week){
             counter++;
         }
    }
    return counter;
}

/**
 * @brief Este algoritmo permite obter a pontuação média por semana
 * 
 * @param listKR Lista que contem todos os dados previamente importados
 *
 */
void totalAverageScore(PtList *listKR){ 
    int ptSize = 0;  
    int size_code = listSize(*listKR,&ptSize);
    if(size_code == LIST_FULL || size_code == LIST_INVALID_RANK || size_code == LIST_NO_MEMORY
    || size_code == LIST_NULL){
        printf("An error ocurred... Please try again...\n");
        return;
    }
    //int a = getQuestions(&kr,1);
    KahootReport kr;
    int week = 0;
    for(int i=0; i<ptSize;i++){
         listGet(*listKR,i,&kr);
         if(kr.week > week){
             week = kr.week;
         }        
    }
    int sum = 0;
    double avg = 0;
    int weeks[week];
    double average[week];
    for(int i=0; i<week; i++){ 
        for(int j=0;j<getQuestions(listKR,i+1); j++){
            sum = sum + kr.total_score;
        }
        avg = sum/getQuestions(listKR,i+1); 
        weeks[i] = i;
        average[i] = avg; 
        sum = 0;
    }
   /*for(int y=0;y<sizeof(weeks)/sizeof(weeks[0]);y++){
        printf("%d",weeks[y]);
    }  
    for(int a=0;a<sizeof(average)/sizeof(average[0]);a++){
        printf("AVG - %2.f", average[a]);
    } */ 
}
