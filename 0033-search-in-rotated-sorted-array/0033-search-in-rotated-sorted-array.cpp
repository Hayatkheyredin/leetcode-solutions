class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int mid;
        while(l<=r){
            mid = l + (r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[l]<=nums[mid]){
            if(target < nums[l] || target>nums[mid]){
                l = mid+1;
            }
            else{
                r= mid-1;
            }
        }
        else{
            if(target>nums[r] || target<nums[mid]){
                r=mid-1;
            }
            else{
                l = mid+1;
            }
        }
        }
        return -1;
    }
};