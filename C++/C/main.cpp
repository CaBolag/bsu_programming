#include <iostream>
#include "functions.h"

int main() {
  int nlines;
  if((nlines=readlines(lineptr,MAXLINES))>=0){
    qsort(lineptr,0,nlines-1);
    return 0;
  }
  else {
    printf("error:input too big to sort\n");
    return 1;
  }
}
