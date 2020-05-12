#include <string.h>
#include "listElem.h"

char ** split(char *string, int nFields, const char *delim);
void importKahootFromFile(char *filename, ListElem *listKR);