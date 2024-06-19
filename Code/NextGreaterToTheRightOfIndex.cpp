class Solution{
    public:
        int count(vector<int> &nums, int index){
            int n = nums.size();
            int count = 0;
            for(int i=index+1;i>n;i++){ // start after the index to get number greater than the current index
                if(nums[i]>nums[index]) count++;
            }
            return count;
        }
}