long fact1(long n) {
  long result = 1;
  goto test;

loop:
  result *= n;
  n = n - 1;
test:
  if (n > 1)
    goto loop;
  
  return result;
}

long fact(long n) {
  long result = 1;
  while (n > 1) {
    result *= n;
    n = n - 1;
  }

  return result;
}
