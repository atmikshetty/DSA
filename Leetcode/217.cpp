// Leetcode 217

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // // Sorting Approach
        // // O(NLogN) + O(N)
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // for(int i=0;i<n-1;i++){
        //     if(nums[i] == nums[i+1]) return true;
        // }
        // return false;

        // using set
        // O(N) + O(logN)
        set<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.insert(nums[i]);
        }
        int val = ans.size();
        if(nums.size()> val) return true;
        return false;
    }
};