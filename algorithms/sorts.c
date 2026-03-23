#include <stdio.h>

void bubbleSort(int *arr, int arrlen) {

  // iterate over first index, bubling up;
  for (int i = 0, end = arrlen; i < end; end--) {

    for (int j = i; j < arrlen - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // swap; could do the "xor" trick to avoid using an int size space.
        int temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      }
    }
  }

  return;
}

int main(int argc, char **argv) {

  int arrlen = 8;
  int array[8] = {12, 32, 1, 4, 9, 10, 7, -1};

  bubbleSort(array, arrlen);

  printf("[");
  for (int i = 0; i < arrlen; i++) {
    printf("%d, ", array[i]);
  }

  printf("]\n");

  return 0;
}
