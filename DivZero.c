/**/
int foo(int x) {
  int y = 0;

  x = x/0; /* first division by zero */
  x = x/y; /* second division by zero */
  x = 3/x; /* third division by zero */

  return x;
}

void bar() {
  foo(0);
}
