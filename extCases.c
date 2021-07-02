//#pragma GCC warning "Testing issue #26085" /* multi line comment to test #26085 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "extCases.h"

/*
    v null pointer exception
    v division by zero
    v array out of bounds
    v resource leaks
    v memory leaks
    v using uninitialized variables
    v conditions that always evaluate to true or false
*/


unsigned int a[10] = {1,0,0,0,0,0,0,0,0,0};

void arrayOutOfBounds(void){
    size_t i = 0;
    for (;i < 10; i++) {
        a[i] = i;
    }
    a[i] = i;
    printf("%i", a[i]);
}

unsigned char *nullPointerRecursion(unsigned char toggle){
    char *q = 0;
    if(toggle){
        return q;
    }
    else{
        return nullPointerRecursion(toggle);
    }
}

char divZero(char toggle){
    return (10/toggle);
}

char returnTrue(char x){
    return (x==x);
}

char returnUninitialized(void){
    char x;
    return x;
}

int *memLeak(){
   int *ptr = (int *) malloc(sizeof(int));
   return ptr; /* Return without freeing ptr*/
}

int *deref(){
    int *ptr = NULL;
    return ptr;
}

int askForProblems() {
    char *nullPtr;
    int *leakPtr;
    int *nullPtr2;
    int  w;
    char x;
    char y = 1;
    char z = 1;
    
    x = returnUninitialized();
    
    /* Uninitialized value usage */
    if(x < 10){
        arrayOutOfBounds();
        nullPtr = nullPointerRecursion(1==1);
    }
    
    nullPtr = nullPointerRecursion(a[1]);
    
    /* Always TRUE condition */
    x = 0;
    if(returnTrue(x)){
        divZero(a[0]);
    }
    
    leakPtr = memLeak();
    nullPtr2 = deref();
    w = *nullPtr2;

    return 0;
}
