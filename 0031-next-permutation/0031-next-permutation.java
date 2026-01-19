class Solution {
    public void nextPermutation(int[] nums) {

        int n = nums.length;
        int i = n - 2;

        // Step 1: Find the first index from the right where nums[i] < nums[i+1]
        // This is the "pivot" point
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: If such an index exists, find the next greater element on the right
        if (i >= 0) {
            int j = n - 1;

            // Find the first element from the right that is greater than nums[i]
            while (nums[j] <= nums[i]) {
                j--;
            }

            // Swapping nums[i] and nums[j]
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }

        // Step 3: Reverse the part after index i to get the next smallest sequence
        int start = i + 1;
        int end = n - 1;

        // Reversing the right half
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;

            start++;
            end--;
        }
    }
}
