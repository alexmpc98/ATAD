/**
 * @file listElem.c
 * @brief Implements operations for ListElem.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "listElem.h"
#include <stdio.h>

struct listImpl;
typedef struct listImpl *PtList;

void listElemPrint(ListElem elem) {
	printf("%d \n", elem);
}