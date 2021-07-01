#include <stdio.h>
#include "foo.h"


void bar1(int z) {
   foo1(42);
}

void bar2(int z) {
   foo2(0);
}

void bar3(int z) {
   if (z == 0) {
      foo3(z);
   }
}

void main(void){
    bar1(0);
    bar2(0);
    foo3(0);
}