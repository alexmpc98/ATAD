#include <stdio.h>
#include <stdlib.h>
#include "kahoot.h"
#include "utils.h"
#include "list.h"
#include "listElem.h"

int main(){
    PtList kr = NULL; 
    importKahootFromFile("kahootReports.csv",&kr);
    sortByAlphabeticalOrder(&kr);
}