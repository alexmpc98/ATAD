#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "queue.h"
#include "queueElem.h"
#include "stack.h"
#include "stackElem.h"


void convertInfixToPostfix(char *suffix, char ** postfix);

int main(){
    char* expression1 = "+5*79-4";
    char* expression2 = "*+579-4";
    char* expression3 = "/*+5633";
    char* expression4 = "/+37-62";
}

void convertInfixToPostfix(char *infix, char ** postfix){
    int sizeOfInfix = strlen(infix);
    if(sizeOfInfix > 0){
    PtQueue infixQueue = queueCreate(sizeOfInfix);
    PtQueue postfixQueue = queueCreate(sizeOfInfix);
    PtStack stack = stackCreate(sizeOfInfix);
    stackClear(stack);
    queueClear(infixQueue);
    queueClear(postfixQueue);

    queueEnqueue(infixQueue,'(');
    queuePrint(infixQueue);
    for(int i=0;i<sizeOfInfix;i++){
        queueEnqueue(infixQueue,infix[i]); 
        queuePrint(infixQueue);
    }
    queueEnqueue(infixQueue,')');
    queuePrint(infixQueue);
    queueDequeue(infixQueue,infix);
    queuePrint(infixQueue);
    int a=0;
    char b,c; 
    while(!queueIsEmpty(infixQueue)){
        if(isdigit(infix[a])>0){
            int value = infix[a] - '0';
            queueEnqueue(postfixQueue,value);
            queuePrint(postfixQueue);
        }
        else if(infix[a] == '('){
            stackPush(stack,infix[a]);    
            stackPrint(stack);
        }
        else if(infix[a] == '*' || infix[a] == '+' || infix[a] == '-' || infix[a] == '/'){
            while(){
                stackPop(stack,&b);
                stackPrint(stack);
                queueEnqueue(postfixQueue,b);
                queuePrint(postfixQueue);
            }
            stackPush(stack,infix[a]);
            stackPrint(stack);
        }
        else if(infix[a] == ')'){
            while(c != '('){
                stackPop(stack,&c); 
                queueEnqueue(postfixQueue,b);
                queuePrint(postfixQueue);
                stackPrint(stack);
            }
            stackPop(stack,&c);
            stackPrint(stack);
        }
        a++;
    }


    }


}