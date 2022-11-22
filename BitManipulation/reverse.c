#include <stdio.h>
#include <assert.h>

// make use of the property of xor: a ^ b = c, we could get a from c ^ b and get
// b from c ^ a
void inplace_swap(int* a, int* b) {
  *b = *a ^ *b;
  *a = *a ^ *b;
  *b = *a ^ *b;
}

void reverse(int a[], int n) {
  int l, r;
 
  for (l = 0, r = n - 1; l < r; l++, r--) {
    assert(l != r);
    inplace_swap(a + l, a + r);
  }
}

int main(int argc, char* argv[]) {
  int a[] = {1, 2, 3, 4, 5, 6};
  int n = sizeof(a) / sizeof(a[0]);

  printf("a = 1 2 3 4 5 6\n");

  reverse(a, n);

  printf("After reversing the array a:\n");
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
