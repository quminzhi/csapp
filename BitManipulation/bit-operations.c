#include <stdio.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
  int i;
  for (i = 0; i < len; i++) {
    printf(" %.2x", start[i]);
  }
  printf("\n");
}

int main(int argc, char* argv[]) {
  int x = 0x87654321;

  int least_byte_mask = 0xff;
  int a = x & least_byte_mask;
  show_bytes((byte_pointer)&a, sizeof(a));

  int complement_mask = 0xffffff00;
  int b = x ^ complement_mask;
  show_bytes((byte_pointer)&b, sizeof(b));

  int c = x | least_byte_mask;
  show_bytes((byte_pointer)&c, sizeof(c));

  return 0;
}
