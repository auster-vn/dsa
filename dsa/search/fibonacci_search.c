#include <stdio.h>

int fibMonacciSearch(int arr[], int x, int n) {
  int fibMMn2 = 0;
  int fibMMn1 = 1;
  int fibM = fibMMn1 + fibMMn2;

  while (fibM < n) {
    fibMMn2 = fibMMn1;
    fibMMn1 = fibM;
    fibM = fibMMn1 + fibMMn2;
  }

  int offset = -1;

  while (fibM > 1) {
    int i = ((offset + fibMMn2) < (n - 1)) ? (offset + fibMMn2) : (n - 1);

    if (arr[i] < x) {
      fibM = fibMMn1;
      fibMMn1 = fibMMn2;
      fibMMn2 = fibM - fibMMn1;
      offset = i;
    }

    else if (arr[i] > x) {
      fibM = fibMMn2;
      fibMMn1 = fibMMn1 - fibMMn2;
      fibMMn2 = fibM - fibMMn1;
    }

    else
      return i;
  }
  if (fibMMn1 && arr[offset + 1] == x)
    return offset + 1;
  return -1;
}
int main() {
  int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 85;
  printf("Found at idx: %d", fibMonacciSearch(arr, x, n));
  return 0;
}
