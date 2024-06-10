class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums,k-1);
    }
    int helper(vector<int>& nums, int k){
        int n = nums.size();
        int left=0,right=0,sum=0,count=0;
        while(right<n){
            sum += nums[right] % 2;
            while(sum>k){
                sum = sum - nums[left]%2;
                left++;
            }
            count = count + (right - left + 1);
            right++;
        }
        return count;
    }
};