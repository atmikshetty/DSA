class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // Brute force
        int length = 0;
        int maxLen = 0;
        for(int i=0;i<nums.size();i++){
            int zeros = 0;
            for(int j=i;j<nums.size();j++){
                if(nums[j] == 0) zeros++;
                if(zeros<=k){
                    length = j - i + 1;
                    maxLen = max(length, maxLen);
                }
                else break;
            }
        }
        return maxLen;

        // Sliding window
        int n = nums.size();
        int left = 0, right = 0, length = 0, maxLength = 0, zeros = 0;
        while(right<n){
            if(nums[right] == 0) zeros++;
            while(zeros>k){
                if(nums[left] == 0) zeros--;
                left++;
            }
            if(zeros<=k){
                length = right - left + 1;
                maxLength = max(length, maxLength);
            }
            right++;
        }
        return maxLength;

        // Optimal
        int n = nums.size();
        int left = 0, right = 0, length = 0, maxLength = 0, zeros = 0;
        while(right<n){
            if(nums[right] == 0) zeros++;
            if(zeros>k){
                if(nums[left] == 0) zeros--;
                left++;
            }
            if(zeros<=k){
                length = right - left + 1;
                maxLength = max(length, maxLength);
            }
            right++;
        }
        return maxLength;
    }
};