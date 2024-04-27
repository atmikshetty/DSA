class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        // //  1st approach - Wrong
        // int ans = pq.top() + 1 - k;
        // return ans;

        for(int i=0;i<k-1;i++){
            pq.pop();
        }
        return pq.top();
    }
};