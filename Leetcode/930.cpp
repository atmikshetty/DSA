class Solution {
public:

    int ans(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int n = nums.size();
        int left=0, right=0, sum=0, count=0;
        while(right<n){
            sum += nums[right];
            while(sum>goal){
                sum = sum - nums[left];
                left++;
            }
            count = count + (right - left + 1);
            right++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return ans(nums, goal) - ans(nums, goal-1);
    }
};