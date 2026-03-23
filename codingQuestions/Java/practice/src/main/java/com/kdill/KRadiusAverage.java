package com.kdill;

class Solution {
  public int[] getAverages(int[] nums, int k) {

    int[] result = new int[nums.length];

    for (int i = 0; i < nums.length; i++) {
      result[i] = -1;
    }

    // edge cases: k > nums.length / 2
    if ((2 * k + 1) > nums.length) {
      return result;
    }

    int left = k;
    int right = nums.length - 1 - k;

    // loop over these computing average.
    // the numerator is effectively a sliding window
    // make the numerator as a sum of -k to +k from left first
    long numerator = 0;
    for (int kindex = Math.max(left - k, 0); kindex <= Math.min(left + k, nums.length - 1); kindex++) {
      numerator += nums[kindex];
    }
    int avg = (int) (numerator / (long) (2 * k + 1));
    result[left] = avg;
    left++;

    // System.out.println("first: "+ avg+ ", numerator: " + numerator);

    while (left <= right) {
      // slide the window and move left+1
      numerator -= nums[left - k - 1];
      numerator += nums[left + k];

      // insert into "left"
      avg = (int) (numerator / (2 * k + 1));
      result[left] = avg;

      left++;
    }

    return result;

  }
}
