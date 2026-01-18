class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Place each number x at index x-1
        for(int i = 0; i < n; i++){
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
                swap(nums[nums[i] - 1], nums[i]);
            }
        }

        // Step 2: Find the first index that doesn't hold the expected value
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1) return i + 1;
        }

        // Step 3: If all positions are correct, return n + 1
        return n + 1;
    }
};