#include <stdio.h>
#include <stdlib.h>
#include "kahoot.h"
#include "utils.h"
#include "listElem.h"

int main(){
    KahootReport *kr = []; 
    importKahootFromFile("kahootReports.csv",kr);
}