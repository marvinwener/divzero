#include <stdio.h>
#include "foo.h"

int foo1(int x) {
   int result = 0;

   result = 42/0; /* first division by zero */
   return result;
}

int foo2(int x) {
   int y = 0;
   int result = 0;
   result = 42/y; /* second division by zero */
   return result;
}

int foo3(int x) {
   int result = 0;
   result = 3/x; /* third division by zero */
   return result;
}
