#include <stdio.h>
#include <stdlib.h>
#include "kahoot.h"
#include "utils.h"
#include "list.h"
#include "listElem.h"

int main(){
    PtList kr = NULL; 
    importKahootFromFile("kahootReports.csv",&kr);
    // Nivel 3.11
    sortByAlphabeticalOrder(&kr);
    listPrint(kr);
    listDestroy(&kr);

    // Nivel 3.12
    importKahootFromFile("kahootReports.csv",&kr);
    sortByWeekAscendingOrder(&kr);
    listPrint(kr);
    
    
}