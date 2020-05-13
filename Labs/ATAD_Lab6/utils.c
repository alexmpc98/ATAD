#include "utils.h"
#include "listElem.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "kahoot.h"
#include "list.h"


char** split(char *string, int nFields, const char *delim){
    char **tokens = (char**) malloc(sizeof(char*) * nFields);

    int index = 0;
    char *token = (char*)strtok(string,delim);

    while(token){
        tokens[index++] = token;
        token = strtok(NULL,delim);
    }
    return tokens;
}

void importKahootFromFile(char *filename, PtList *listKR){
    FILE *f = NULL;

    f = fopen(filename,"r");
    if(f == NULL){
        printf("An error ocurred... It was not possible to open the file %s ...\n",filename);
        return;
    }

    char nextline[1024];
    int countKR = 0; // kahoot report count
    bool firstline = true;

    *listKR = listCreate(10);

    while(fgets(nextline,sizeof(nextline),f)){
        if(strlen(nextline) < 1 )
            continue;

    /* As the first line of the file contains the name of the fields it should be ignored */
    if(firstline){
        firstline = false;
        continue;
    }

    char **tokens = split(nextline,6,";");

    // At this moment the tokens array is composed with the following "strings"
    //tokens[0] - week
    //tokens[1] - rank
    //tokens[2] - nickname;
    //tokens[3] - total_score;
    //tokens[4] - correct_answers;
    //tokens[5] - incorrect_answers;

    KahootReport kr = KahootReportCreate(atoi(tokens[0]),atoi(tokens[1]),tokens[2],atoi(tokens[3]),
    atoi(tokens[4]),atoi(tokens[5]));

    free(tokens);
    
    int error_code = listAdd(*listKR,countKR,kr);
    
    if(error_code == LIST_FULL || error_code == LIST_INVALID_RANK || error_code == LIST_NO_MEMORY
    || error_code == LIST_NULL){
        printf("An error ocurred... Please try again...\n");
        return;
    }
    countKR++;
}
    printf("\n\n%d kahoot reports were read!\n\n",countKR);
    fclose(f);
}

void sortByAlphabeticalOrder(PtList *listKR){
    int ptSize = 0;  
    int size_code = listSize(*listKR,&ptSize);
    if(size_code == LIST_FULL || size_code == LIST_INVALID_RANK || size_code == LIST_NO_MEMORY
    || size_code == LIST_NULL){
        printf("An error ocurred... Please try again...\n");
        return;
    }
    int a = 0;
    int b = 0;
    int c = 0;
    KahootReport kr;
    KahootReport kr2;
    KahootReport kr3;
    for(int i=0; i<ptSize-1;i++){
        a = listGet(*listKR,i,&kr);
        for(int j=i+1;j<ptSize;j++){
            b = listGet(*listKR,i,&kr2);
            if(kr.nickname < kr2.nickname){
               printf("Actually Bigger %d %d",i,j);
                kr3 = kr;
                kr = kr2;
                kr2 = kr3;
                c = listSet(*listKR,i,kr2,&kr);
            }
        }
    } 
    listPrint(*listKR);
}