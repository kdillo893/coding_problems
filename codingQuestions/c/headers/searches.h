#ifndef SEARCHES_H

#define SEARCHES_H

/**
 * returns the index of the value from search or -1 if not found
 */
int linearSearch(int *nums, int numsLen, int val);

/**
 * nums must be sorted for binary search
 * NOTE: if this were a "search" for something else, would need comparison
 * function
 * returns the index of the value from search or -1 if not found
 */
int binarySearch(int *nums, int numsLen, int val);

#endif // !SEARCHES_H
