#ifndef SORTS_H
#define SORTS_H

/**You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
    representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order. (increasing??? wtf?)

The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
  To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, 
  and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/
void mergeSort(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);

/**
  simplest version of merge, has edge cases and other problems.
*/
void mergeSortv1(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);
void mergeSortv2(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);
void mergeSortv3(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);

/**
 * bubble sort,
 * nums contains pointer to array of ints,
 * numsLen is length of the array,
 * c (if I care to use it) is the capacity of the pointer
 */
void bubbleSort(int* nums, int numsLen, int c);

void insertionSort(int* nums, int numsLen, int c);


#endif //! SORTS_H
