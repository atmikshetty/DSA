class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);
        for(int i=2*n-1;i>=0;i--){  // consider nums + nums
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
           if(i<n){
            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
           }
           st.push(nums[i%n]);
        }
        return ans;
    }
};