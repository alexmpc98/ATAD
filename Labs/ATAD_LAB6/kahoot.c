#include "kahoot.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

KahootReport KahootReportCreate(int week, int rank, char nickname[50], int total_score,int correct_answers, int incorrect_answers){
    KahootReport kr;
    kr.week = week;
    kr.rank = rank;
    strcpy(kr.nickname,nickname);
    kr.total_score = total_score;
    kr.correct_answers = correct_answers;
    kr.incorrect_answers = incorrect_answers;
    return kr;
}
void KahootReportPrint(KahootReport kr){
    printf("%d | %d | %s | %d | %d | %d\n",kr.week,kr.rank,kr.nickname,kr.total_score,kr.correct_answers,kr.incorrect_answers);
}