#include <stdio.h>

// make use of the property of xor: a ^ b = c, we could get a from c ^ b and get
// b from c ^ a
void inplace_swap(int* a, int* b) {
  *b = *a ^ *b;
  *a = *a ^ *b;
  *b = *a ^ *b;
}

int main(int argc, char* argv[]) {
  int a, b;

  scanf("%d%d", &a, &b);

  inplace_swap(&a, &b);

  printf("After inplace swap, a = %d and b = %d.", a, b);

  return 0;
}
