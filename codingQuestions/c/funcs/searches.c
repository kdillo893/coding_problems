#include "../headers/searches.h"


int linearSearch(int *nums, int numsLen, int val) {

  for (int i = 0; i < numsLen; i++) {
    if (nums[i] == val) {
      return i;
    }
  }

  return -1;
}

int binarySearch(int *nums, int numsLen, int val) {

  int top = numsLen - 1;
  int bottom = 0;

  // if numslen 0, no entries and just returns
  while (bottom <= top) {
    int i = (numsLen + bottom) / 2;

    if (val < nums[i]) {
      top = i-1;
    } else if (val > nums[i]) {
      bottom = i+1;
    } else {
      return i;
    }
  }

  return -1;
}


