#include "bytes.h"

int main() {
  int x;
  printf("Input a value to store in memory:\n");
  scanf("%d", &x);

  int ival = x;
  float fval = (float)x;
  int* pval = &x;
  
  printf("Byte ordering of integer %d:\n", ival);
  show_int(ival);
  printf("Byte ordering of float %f:\n", fval);
  show_float(fval);
  printf("Byte ordering of address of val %d:\n", x);
  show_pointer(pval);
}
