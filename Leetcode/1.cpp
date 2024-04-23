class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //     // Brute force O(N2)
        //     int n = nums.size();
        //     for(int i=0;i<n;i++){
        //         for(int j=i+1;j<n;j++){
        //             if(nums[i] + nums[j] == target){
        //                 return {i,j};
        //                 break;
        //             }
        //         }
        //     }
        // return {};

        // hash map O(N x logN)
        int n = nums.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            int a = nums[i];
            int remain = target - a;
            if(mpp.find(remain) != mpp.end()){
                return {mpp[remain], i};
            }
            mpp[a] = i;
        } 
        return {};
    }
};